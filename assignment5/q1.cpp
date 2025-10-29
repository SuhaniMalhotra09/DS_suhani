#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// (a) Insertion at the beginning
void insertAtBeginning(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    cout << "Inserted " << value << " at beginning.\n";
}

// (b) Insertion at the end
void insertAtEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    cout << "Inserted " << value << " at end.\n";
}

// (c) Insertion before/after a node
void insertBeforeAfter(int value, int key, bool after) {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    Node* newNode = new Node();
    newNode->data = value;

    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Key not found!\n";
        delete newNode;
        return;
    }

    if (after) { // Insert after the key
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Inserted " << value << " after " << key << ".\n";
    } else { // Insert before the key
        if (temp == head) {
            newNode->next = head;
            head = newNode;
        } else {
            newNode->next = temp;
            prev->next = newNode;
        }
        cout << "Inserted " << value << " before " << key << ".\n";
    }
}

// (d) Deletion from beginning
void deleteFromBeginning() {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    cout << "Deleted " << temp->data << " from beginning.\n";
    delete temp;
}

// (e) Deletion from end
void deleteFromEnd() {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }
    if (head->next == NULL) {
        cout << "Deleted " << head->data << " from end.\n";
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    Node* prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    cout << "Deleted " << temp->data << " from end.\n";
    delete temp;
    prev->next = NULL;
}

// (f) Deletion of specific node
void deleteSpecific(int key) {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }
    Node* temp = head;
    Node* prev = NULL;

    if (head->data == key) {
        head = head->next;
        delete temp;
        cout << "Deleted node " << key << ".\n";
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Key not found!\n";
        return;
    }

    prev->next = temp->next;
    delete temp;
    cout << "Deleted node " << key << ".\n";
}

// (g) Search for a node and display position
void searchNode(int key) {
    Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == key) {
            cout << "Node " << key << " found at position " << pos << ".\n";
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Node not found!\n";
}

// (h) Display all nodes
void display() {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }
    Node* temp = head;
    cout << "Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    int choice, val, key;
    bool after;

    while (true) {
        cout << "\n---- MENU ----\n";
        cout << "1. Insert at Beginning\n2. Insert at End\n3. Insert Before/After\n4. Delete from Beginning\n5. Delete from End\n6. Delete Specific\n7. Search\n8. Display\n9. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: cout << "Enter value: "; cin >> val; insertAtBeginning(val); break;
            case 2: cout << "Enter value: "; cin >> val; insertAtEnd(val); break;
            case 3: cout << "Enter value and key: "; cin >> val >> key;
                    cout << "Insert after(1) or before(0)? "; cin >> after;
                    insertBeforeAfter(val, key, after); break;
            case 4: deleteFromBeginning(); break;
            case 5: deleteFromEnd(); break;
            case 6: cout << "Enter key: "; cin >> key; deleteSpecific(key); break;
            case 7: cout << "Enter key: "; cin >> key; searchNode(key); break;
            case 8: display(); break;
            case 9: exit(0);
            default: cout << "Invalid choice!\n";
        }
    }
}
