#include <iostream>
#include <queue>
using namespace std;

void firstNonRepeating(string str) {
    queue<char> q;
    int freq[26] = {0};

    for (char ch : str) {
        freq[ch - 'a']++;
        q.push(ch);

        while (!q.empty() && freq[q.front() - 'a'] > 1)
            q.pop();

        if (q.empty())
            cout << "-1 ";
        else
            cout << q.front() << " ";
    }
}

int main() {
    string str = "aabc";
    cout << "Input: " << str << endl;
    cout << "Output: ";
    firstNonRepeating(str);
    return 0;
}
