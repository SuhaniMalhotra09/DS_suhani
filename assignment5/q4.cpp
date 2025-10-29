#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
Node* head = NULL;

void insert(int val) {
    Node* n = new Node;
    n->data = val;
    n->next = head;
    head = n;
}

void reverse() {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void display() {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    for (int i = 4; i >= 1; i--) insert(i); // 1 2 3 4
    cout << "Original: "; display();
    reverse();
    cout << "Reversed: "; display();
}
