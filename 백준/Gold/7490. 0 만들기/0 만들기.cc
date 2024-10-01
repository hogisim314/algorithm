#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
int test_case;
int n;

int calc(string expr) {
    int sz = expr.size();
    string tmp;
    for (int i = 0; i < sz; ++i) {
        if (expr[i] != ' ') tmp += expr[i];
    }
    int idx = 0;
    int cnt = 0;
    int res = 0;
    int temp = 0;
    char lastop = '*';
    int stpos = cnt;
    cnt = 0;

    for (int i = stpos; i < tmp.size(); ++i) {
        if (tmp[i] == '+') {
            temp = stoi(tmp.substr(idx, cnt));
            if (lastop == '+') {
                res += temp;
            } else if (lastop == '-') {
                res -= temp;
            } else {
                res += temp;
            }
            lastop = '+';
            cnt = 0;
        } else if (tmp[i] == '-') {
            temp = stoi(tmp.substr(idx, cnt));
            if (lastop == '+') {
                res += temp;
            } else if (lastop == '-') {
                res -= temp;
            } else {
                res += temp;
            }
            lastop = '-';
            cnt = 0;
        } else if (cnt == 0) {
            idx = i;
            cnt++;
        } else {
            cnt++;
        }
    }
    temp = stoi(tmp.substr(idx, cnt));
    if (lastop == '+') {
        res += temp;
    } else if (lastop == '-') {
        res -= temp;
    } else {
        res += temp;
    }
    return res;
}

void foo(int cur, string expr) {
    if (cur == n) {
        int ret = calc(expr);
        if (ret == 0) {
            cout << expr << '\n';
        }
        return;
    }

    string tmp1 = expr + " ";
    tmp1 += (cur + 1 + '0');
    foo(cur + 1, tmp1);
    string tmp2 = expr + "+";
    tmp2 += (cur + 1 + '0');
    foo(cur + 1, tmp2);
    string tmp3 = expr + "-";
    tmp3 += (cur + 1 + '0');
    foo(cur + 1, tmp3);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> test_case;
    stack<char> s;
    s.push(1 + '0');
    for (int t = 1; t <= test_case; ++t) {
        cin >> n;
        string s = "1";
        foo(1, s);
        cout << '\n';
    }
}
