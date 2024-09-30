#include <algorithm>
#include <iostream>
#include <set>
#include <string>
using namespace std;

string S, T;
int successiveA, successiveB;
bool flag = false;
set<string> SET;

void foo(string cur) {
    if (flag) return;
    if (cur.size() < S.size()) return;
    if (cur == S) {
        flag = true;
        return;
    }
    int sz = cur.size();
    if (cur[sz - 1] == 'A') {
        foo(cur.substr(0, sz - 1));
    }
    if (cur[0] == 'B') {
        string temp = "";
        for (int i = sz - 1; i >= 1; --i) {
            temp += cur[i];
        }
        foo(temp);
    }
}

int main() {
    cin >> S >> T;
    foo(T);
    cout << flag;
}