#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

Node* insertNode(Node* root, int value) {
    if (root == NULL)
        return new Node(value);

    if (value < root->data)
        root->left = insertNode(root->left, value);
    else
        root->right = insertNode(root->right, value);

    return root;
}

Node* searchRecursive(Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return searchRecursive(root->left, key);
    else
        return searchRecursive(root->right, key);
}

Node* searchNonRecursive(Node* root, int key) {
    while (root != NULL) {
        if (key == root->data)
            return root;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}

Node* findMin(Node* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

Node* findMax(Node* root) {
    while (root && root->right != NULL)
        root = root->right;
    return root;
}

Node* inorderSuccessor(Node* root, Node* target) {
    if (target->right != NULL)
        return findMin(target->right);

    Node* succ = NULL;
    while (root != NULL) {
        if (target->data < root->data) {
            succ = root;
            root = root->left;
        } else if (target->data > root->data) {
            root = root->right;
        } else {
            break;
        }
    }
    return succ;
}

Node* inorderPredecessor(Node* root, Node* target) {
    if (target->left != NULL)
        return findMax(target->left);

    Node* pred = NULL;
    while (root != NULL) {
        if (target->data > root->data) {
            pred = root;
            root = root->right;
        } else if (target->data < root->data) {
            root = root->left;
        } else {
            break;
        }
    }
    return pred;
}

int main() {
    Node* root = NULL;
    int arr[] = {50, 30, 20, 40, 70, 60, 80};

    for (int x : arr)
        root = insertNode(root, x);

    Node* r1 = searchRecursive(root, 40);
    Node* r2 = searchNonRecursive(root, 60);

    Node* mn = findMin(root);
    Node* mx = findMax(root);

    Node* node = searchRecursive(root, 50);
    Node* succ = inorderSuccessor(root, node);
    Node* pred = inorderPredecessor(root, node);

    cout << "Search Recursive: " << (r1 ? r1->data : -1) << endl;
    cout << "Search Non-Recursive: " << (r2 ? r2->data : -1) << endl;
    cout << "Min: " << mn->data << endl;
    cout << "Max: " << mx->data << endl;
    cout << "Inorder Successor of 50: " << (succ ? succ->data : -1) << endl;
    cout << "Inorder Predecessor of 50: " << (pred ? pred->data : -1) << endl;

    return 0;
}
