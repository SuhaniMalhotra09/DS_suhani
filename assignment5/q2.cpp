#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insert(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

void countAndDeleteKey(int key) {
    int count = 0;
    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL) {
        if (temp->data == key) {
            count++;
            if (temp == head) {
                head = head->next;
                delete temp;
                temp = head;
            } else {
                prev->next = temp->next;
                delete temp;
                temp = prev->next;
            }
        } else {
            prev = temp;
            temp = temp->next;
        }
    }

    cout << "Count: " << count << "\nUpdated List: ";
    temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next) cout << "->";
        temp = temp->next;
    }
    cout << "\n";
}

int main() {
    // Input: 1->2->1->2->1->3->1
    int arr[] = {1,2,1,2,1,3,1};
    for (int i = 6; i >= 0; i--) insert(arr[i]);

    int key;
    cout << "Enter key: ";
    cin >> key;
    countAndDeleteKey(key);
}
