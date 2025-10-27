#include <iostream>

using namespace std;

bool Balanced(string exp) {
    stack<char> s;

    
    for (int i = 0; i < exp.length(); i++) {
        char ch = exp[i];  

        if (ch == '(' || ch == '{' || ch == '[')
            s.push(ch);
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty())
                return false;

            char top = s.top();
            s.pop();

            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '['))
                return false;
        }
    }
    return s.empty();
}

int main() {
    string expression;
    cout << "Enter an expression: ";
    cin >> expression;

    if (Balanced(expression))
        cout << "Balanced Parentheses";
    else
        cout << "Not Balanced";

    return 0;
}
