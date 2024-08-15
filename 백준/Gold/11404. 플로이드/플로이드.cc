#include <algorithm>
#include <iostream>
using namespace std;
int n, m;
int a, b, c;
int dist[111][111];
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

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cout << dist[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
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
}