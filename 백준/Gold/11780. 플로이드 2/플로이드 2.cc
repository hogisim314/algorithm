#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n, m;
int a, b, c;
int dist[111][111];
int via[111][111];
vector<int> way;

void backtrack(int start, int end) {
    int bypass = via[start][end];
    if (bypass == 0) {
        way.push_back(end);
        return;
    }
    backtrack(start, bypass);
    backtrack(bypass, end);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    cin >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            dist[i][j] = 210000000;
        }
    }

    for (int i = 1; i <= m; i++) {
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][j] <= dist[i][k] + dist[k][j]) {
                    continue;
                } else {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    via[i][j] = k;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == 210000000) {
                cout << 0 << ' ';
            } else
                cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j || dist[i][j] == 210000000) {
                cout << 0 << '\n';
            } else {
                if (via[i][j] == 0) {
                    cout << 2 << ' ' << i << ' ' << j << '\n';
                } else {
                    way.clear();
                    way.push_back(i);
                    backtrack(i, j);
                    cout << way.size() << ' ';
                    for (int i = 0; i < way.size(); i++) {
                        cout << way[i] << ' ';
                    }
                    cout << '\n';
                }
            }
        }
    }
}