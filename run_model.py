
import os
import random
from PIL import Image, ImageDraw
import numpy as np
import tensorflow as tf
import shutil

# --- 0. Synthetic Data Generation ---

# Create directories if they don't exist, cleaning them first
if os.path.exists('dataset'):
    shutil.rmtree('dataset')
os.makedirs('dataset/cracked', exist_ok=True)
os.makedirs('dataset/uncracked', exist_ok=True)

# Image dimensions
width, height = 256, 256

# Number of images to generate for each class
num_images = 100

# Generate Uncracked Images
for i in range(num_images):
    image = Image.new('RGB', (width, height), color='gray')
    pixels = np.array(image)
    noise = np.random.randint(-20, 20, (height, width, 3))
    pixels = np.clip(pixels + noise, 0, 255).astype(np.uint8)
    image = Image.fromarray(pixels)
    image.save(f'dataset/uncracked/image_{i}.png')

# Generate Cracked Images
for i in range(num_images):
    image = Image.new('RGB', (width, height), color='gray')
    pixels = np.array(image)
    noise = np.random.randint(-20, 20, (height, width, 3))
    pixels = np.clip(pixels + noise, 0, 255).astype(np.uint8)
    image = Image.fromarray(pixels)
    draw = ImageDraw.Draw(image)
    x1, y1 = random.randint(0, width), random.randint(0, height)
    x2, y2 = random.randint(0, width), random.randint(0, height)
    draw.line((x1, y1, x2, y2), fill='black', width=random.randint(1, 3))
    image.save(f'dataset/cracked/image_{i}.png')

print("Synthetic dataset generated successfully!")


# --- 1. Data Loading and Preprocessing ---

# Define constants
IMG_HEIGHT = 128
IMG_WIDTH = 128
BATCH_SIZE = 32

# Load the dataset
train_ds = tf.keras.utils.image_dataset_from_directory(
    'dataset',
    validation_split=0.2,
    subset="training",
    seed=123,
    image_size=(IMG_HEIGHT, IMG_WIDTH),
    batch_size=BATCH_SIZE
)

val_ds = tf.keras.utils.image_dataset_from_directory(
    'dataset',
    validation_split=0.2,
    subset="validation",
    seed=123,
    image_size=(IMG_HEIGHT, IMG_WIDTH),
    batch_size=BATCH_SIZE
)

# Get class names
class_names = train_ds.class_names
print("Class names:", class_names)

# Normalize the pixel values
normalization_layer = tf.keras.layers.Rescaling(1./255)
train_ds = train_ds.map(lambda x, y: (normalization_layer(x), y))
val_ds = val_ds.map(lambda x, y: (normalization_layer(x), y))

# --- 2. Model Implementation ---

num_classes = len(class_names)

model = tf.keras.Sequential([
    tf.keras.layers.Conv2D(32, 3, activation='relu', input_shape=(IMG_HEIGHT, IMG_WIDTH, 3)),
    tf.keras.layers.MaxPooling2D(),
    tf.keras.layers.Conv2D(32, 3, activation='relu'),
    tf.keras.layers.MaxPooling2D(),
    tf.keras.layers.Conv2D(32, 3, activation='relu'),
    tf.keras.layers.MaxPooling2D(),
    tf.keras.layers.Flatten(),
    tf.keras.layers.Dense(128, activation='relu'),
    tf.keras.layers.Dense(num_classes)
])

model.compile(
    optimizer='adam',
    loss=tf.keras.losses.SparseCategoricalCrossentropy(from_logits=True),
    metrics=['accuracy']
)

# --- 3. Model Training ---

epochs = 10
history = model.fit(
    train_ds,
    validation_data=val_ds,
    epochs=epochs
)

# --- 4. Model Evaluation ---

loss, accuracy = model.evaluate(val_ds)
print(f"Validation accuracy: {accuracy:.4f}")
print(f"Validation loss: {loss:.4f}")
