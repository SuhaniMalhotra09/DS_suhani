#include <iostream>
using namespace std;
#define SIZE 5

class CircularQueue {
    int arr[SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return ((rear + 1) % SIZE == front);
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full!\n";
            return;
        }
        if (front == -1)
            front = 0;
        rear = (rear + 1) % SIZE;
        arr[rear] = value;
        cout << value << " inserted.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << arr[front] << " deleted.\n";
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % SIZE;
    }

    void peek() {
        if (!isEmpty())
            cout << "Front element: " << arr[front] << endl;
        else
            cout << "Queue is empty!\n";
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue cq;
    int choice, value;

    do {
        cout << "\n1.Enqueue 2.Dequeue 3.Peek 4.Display 5.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            cq.enqueue(value);
            break;
        case 2:
            cq.dequeue();
            break;
        case 3:
            cq.peek();
            break;
        case 4:
            cq.display();
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
