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

void findMiddle() {
    if (head == NULL) {
        cout << "Empty list\n";
        return;
    }
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << "Middle element: " << slow->data << endl;
}

int main() {
    for (int i = 5; i >= 1; i--) insert(i); // 1 2 3 4 5
    findMiddle();
}
