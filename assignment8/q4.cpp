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

Node* insert(Node* root, int value) {
    if (root == NULL)
        return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

bool isBSTUtil(Node* root, int &prev) {
    if (root == NULL)
        return true;

    if (!isBSTUtil(root->left, prev))
        return false;

    if (root->data <= prev)
        return false;

    prev = root->data;

    return isBSTUtil(root->right, prev);
}

bool isBST(Node* root) {
    int prev = -1000000;
    return isBSTUtil(root, prev);
}

int main() {
    Node* root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    if (isBST(root))
        cout << "It is a BST";
    else
        cout << "It is NOT a BST";

    return 0;
}
