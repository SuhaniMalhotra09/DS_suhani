#include <iostream>

using namespace std;

int evaluatePostfix(string exp) {
    stack<int> s;

    for (int i = 0; i < exp.length(); i++) {
        char ch = exp[i];

        if (isdigit(ch)) {
            s.push(ch - '0');
        } 
        else {
            int val2 = s.top(); s.pop();
            int val1 = s.top(); s.pop();

            switch (ch) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
                case '^': s.push(pow(val1, val2)); break;
            }
        }
    }

    return s.top();
}

int main() {
    string exp;
    cout << "Enter a postfix expression: ";
    cin >> exp;

    cout << "Result = " << evaluatePostfix(exp) << endl;
    return 0;
}
