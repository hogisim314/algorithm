#include <limits.h>
#include <memory.h>
#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int m, n;
int grid[111][111];
int di[] = {1, 0, -1, 0};
int dj[] = {0, 1, 0, -1};
bool visited[111][111];
int crash[111][111];

bool is_ok(int i, int j) {
    if (i < 1 || i > n || j < 1 || j > m) {
        return false;
    }
    return true;
}

void bfs(int i, int j) {
    queue<pair<int, int> > q;
    q.push(make_pair(1, 1));

    while (!q.empty()) {
        int topi = q.front().first;
        int topj = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int tempi = topi + di[i];
            int tempj = topj + dj[i];
            if (is_ok(tempi, tempj)) {
                if (crash[tempi][tempj] == 30000) {
                    q.push(make_pair(tempi, tempj));
                    crash[tempi][tempj] = grid[tempi][tempj]
                                              ? crash[topi][topj] + 1
                                              : crash[topi][topj];
                } else {
                    if (grid[tempi][tempj] == 1 &&
                        crash[tempi][tempj] > crash[topi][topj] + 1) {
                        crash[tempi][tempj] = crash[topi][topj] + 1;
                        q.push(make_pair(tempi, tempj));
                    } else if (grid[tempi][tempj] == 0 &&
                               crash[tempi][tempj] > crash[topi][topj]) {
                        crash[tempi][tempj] = crash[topi][topj];
                        q.push(make_pair(tempi, tempj));
                    }
                }
            }
        }
    }
}

int main() {
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%1d", &grid[i][j]);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            crash[i][j] = 30000;
        }
    }
    crash[1][1] = 0;
    bfs(1, 1);

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         cout << crash[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    cout << crash[n][m];
}