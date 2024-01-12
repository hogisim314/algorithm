#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n, m;
int arr[2005];
int pldr[2005][2005];
int half_length;
queue<pair<int, int> > q;
int s, e;
int l, r;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        pldr[i][i] = 1;
        q.push(make_pair(i, i));
    }

    for (int i = 1; i <= n - 1; i++) {
        if (arr[i] == arr[i + 1]) {
            pldr[i][i + 1] = 1;
            q.push(make_pair(i, i + 1));
        }
    }

    while (!q.empty()) {
        l = q.front().first;
        r = q.front().second;
        q.pop();
        if (pldr[l][r] && l - 1 >= 1 && r + 1 <= n &&
            arr[l - 1] == arr[r + 1]) {
            pldr[l - 1][r + 1] = 1;
            q.push(make_pair(l - 1, r + 1));
        }
    }

    cin >> m;
    while (m--) {
        cin >> s >> e;
        cout << pldr[s][e] << '\n';
    }
}