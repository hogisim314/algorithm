#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n, m;
int di[] = {1, 0, -1, 0};
int dj[] = {0, 1, 0, -1};
int arr[1111][1111];
int visited[1111][1111];
int ti, tj;
int topi, topj;
int nexti, nextj;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) {
                ti = i;
                tj = j;
            }
            visited[i][j] = -1;
        }
    }

    queue<pair<int, int> > q;
    q.emplace(make_pair(ti, tj));
    visited[ti][tj] = 0;
    while (!q.empty()) {
        topi = q.front().first;
        topj = q.front().second;
        q.pop();
        for (int d = 0; d < 4; ++d) {
            nexti = topi + di[d];
            nextj = topj + dj[d];
            if (nexti < 1 || nexti > n || nextj < 1 || nextj > m ||
                arr[nexti][nextj] == 0 || visited[nexti][nextj] >= 0)
                continue;
            q.emplace(make_pair(nexti, nextj));
            visited[nexti][nextj] = visited[topi][topj] + 1;
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (arr[i][j] == 0) {
                cout << 0 << ' ';
            } else
                cout << visited[i][j] << ' ';
        }
        cout << '\n';
    }
}