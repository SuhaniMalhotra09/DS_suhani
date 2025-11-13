#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
};

struct CNode {
    int data;
    CNode* next;
};

DNode* insertDoubly(DNode* head, int data, int pos) {
    DNode* newNode = new DNode{data, nullptr, nullptr};
    if (pos == 1) {
        newNode->next = head;
        if (head) head->prev = newNode;
        head = newNode;
        return head;
    }
    DNode* temp = head;
    for (int i = 1; temp && i < pos - 1; i++)
        temp = temp->next;
    if (!temp) {
        cout << "Position not found.\n";
        delete newNode;
        return head;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next)
        temp->next->prev = newNode;
    temp->next = newNode;
    return head;
}

DNode* deleteDoubly(DNode* head, int key) {
    if (!head) return head;
    DNode* temp = head;
    while (temp && temp->data != key)
        temp = temp->next;
    if (!temp) {
        cout << "Node not found.\n";
        return head;
    }
    if (temp->prev)
        temp->prev->next = temp->next;
    else
        head = temp->next;
    if (temp->next)
        temp->next->prev = temp->prev;
    delete temp;
    cout << "Node " << key << " deleted.\n";
    return head;
}

void searchDoubly(DNode* head, int key) {
    int pos = 1;
    while (head) {
        if (head->data == key) {
            cout << "Node " << key << " found at position " << pos << endl;
            return;
        }
        head = head->next;
        pos++;
    }
    cout << "Node not found.\n";
}

void displayDoubly(DNode* head) {
    cout << "Doubly Linked List: ";
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

CNode* insertCircular(CNode* last, int data, int pos) {
    CNode* newNode = new CNode{data, nullptr};
    if (!last) {
        newNode->next = newNode;
        return newNode;
    }
    CNode* temp = last->next;
    if (pos == 1) {
        newNode->next = temp;
        last->next = newNode;
        return last;
    }
    for (int i = 1; temp != last && i < pos - 1; i++)
        temp = temp->next;
    newNode->next = temp->next;
    temp->next = newNode;
    if (temp == last) last = newNode;
    return last;
}

CNode* deleteCircular(CNode* last, int key) {
    if (!last) return nullptr;
    CNode* curr = last->next;
    CNode* prev = last;
    do {
        if (curr->data == key) {
            if (curr == last && curr == last->next) {
                delete curr;
                return nullptr;
            }
            if (curr == last) last = prev;
            prev->next = curr->next;
            delete curr;
            cout << "Node " << key << " deleted.\n";
            return last;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != last->next);
    cout << "Node not found.\n";
    return last;
}

void searchCircular(CNode* last, int key) {
    if (!last) {
        cout << "List empty.\n";
        return;
    }
    CNode* temp = last->next;
    int pos = 1;
    do {
        if (temp->data == key) {
            cout << "Node " << key << " found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != last->next);
    cout << "Node not found.\n";
}

void displayCircular(CNode* last) {
    if (!last) {
        cout << "List empty.\n";
        return;
    }
    CNode* temp = last->next;
    cout << "Circular Linked List: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != last->next);
    cout << endl;
}

int main() {
    DNode* dHead = nullptr;
    CNode* cLast = nullptr;
    int choice, type, data, pos, key;
    while (true) {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        if (choice == 5) break;
        cout << "Choose List Type: 1. Doubly  2. Circular: ";
        cin >> type;
        switch (choice) {
        case 1:
            cout << "Enter data: ";
            cin >> data;
            cout << "Enter position (1 for beginning): ";
            cin >> pos;
            if (type == 1) dHead = insertDoubly(dHead, data, pos);
            else cLast = insertCircular(cLast, data, pos);
            break;
        case 2:
            cout << "Enter node value to delete: ";
            cin >> key;
            if (type == 1) dHead = deleteDoubly(dHead, key);
            else cLast = deleteCircular(cLast, key);
            break;
        case 3:
            cout << "Enter node value to search: ";
            cin >> key;
            if (type == 1) searchDoubly(dHead, key);
            else searchCircular(cLast, key);
            break;
        case 4:
            if (type == 1) displayDoubly(dHead);
            else displayCircular(cLast);
            break;
        default:
            cout << "Invalid choice.\n";
        }
    }
    return 0;
}

