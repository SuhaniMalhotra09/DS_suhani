#include <iostream>
#include <queue>
using namespace std;

class Stack {
    queue<int> q1, q2;

public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Popped: " << q1.front() << endl;
        q1.pop();
    }

    void top() {
        if (!q1.empty())
            cout << "Top element: " << q1.front() << endl;
        else
            cout << "Stack is empty\n";
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.top();
    s.pop();
    s.top();
    return 0;
}
