#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
using namespace std;
int n;
string cmd;
stack<int> s;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> cmd;
        if (cmd == "push") {
            int x;
            cin >> x;
            s.push(x);
        } else if (cmd == "pop") {
            if (s.empty()) {
                cout << "-1" << '\n';
                continue;
            }
            cout << s.top() << '\n';
            s.pop();

        } else if (cmd == "size") {
            cout << s.size() << '\n';
        } else if (cmd == "empty") {
            if (s.empty()) {
                cout << 1 << '\n';
            } else
                cout << 0 << '\n';
        } else if (cmd == "top") {
            if (s.empty()) {
                cout << "-1" << '\n';
                continue;
            }
            cout << s.top() << '\n';
        }
    }
}