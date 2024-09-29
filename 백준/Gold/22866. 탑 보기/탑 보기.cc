#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;
#define INF 987654321
int N;
int H[111111];
int dpright[111111];
int dpleft[111111];
int idx[111111];
int idx1[111111];
stack<pair<int, int> > s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> H[i];
    }

    for (int i = N; i >= 1; --i) {
        if (s.empty()) {
            dpright[i] = 0;
            idx[i] = INF;
            s.push(make_pair(H[i], i));
        } else {
            if (s.top().first > H[i]) {
                idx[i] = s.top().second;
                dpright[i] = dpright[idx[i]] + 1;
                s.push(make_pair(H[i], i));
            } else {
                while (!s.empty() && s.top().first <= H[i]) {
                    s.pop();
                }
                if (s.empty()) {
                    idx[i] = INF;
                    dpright[i] = 0;
                    s.push(make_pair(H[i], i));
                } else if (!s.empty()) {
                    idx[i] = s.top().second;
                    dpright[i] = dpright[idx[i]] + 1;
                    s.push(make_pair(H[i], i));
                }
            }
        }
    }
    while (!s.empty()) {
        s.pop();
    }
    for (int i = 1; i <= N; ++i) {
        if (s.empty()) {
            dpleft[i] = 0;
            idx1[i] = -INF;
            s.push(make_pair(H[i], i));
        } else {
            if (s.top().first > H[i]) {
                idx1[i] = s.top().second;
                dpleft[i] = dpleft[idx1[i]] + 1;
                s.push(make_pair(H[i], i));
            } else {
                while (!s.empty() && s.top().first <= H[i]) {
                    s.pop();
                }
                if (s.empty()) {
                    idx1[i] = -INF;
                    dpleft[i] = 0;
                    s.push(make_pair(H[i], i));
                } else if (!s.empty()) {
                    idx1[i] = s.top().second;
                    dpleft[i] = dpleft[idx1[i]] + 1;
                    s.push(make_pair(H[i], i));
                }
            }
        }
    }
    for (int i = 1; i <= N; ++i) {
        cout << dpleft[i] + dpright[i];
        if (dpleft[i] + dpright[i] == 0)
            cout << '\n';
        else {
            cout << ' ';
            if (i - idx1[i] == idx[i] - i) {
                cout << idx1[i] << '\n';
            } else {
                if (i - idx1[i] > idx[i] - i) {
                    cout << idx[i] << '\n';
                } else {
                    cout << idx1[i] << '\n';
                }
            }
        }
    }
}