#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define INF 987654321
int n, k;

int dist[444][444];
int a, b;
int s;

void floyd_warshall() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = INF;
        }
    }

    for (int i = 1; i <= k; i++) {
        cin >> a >> b;
        dist[a][b] = 1;  // a에서 b가는 경로 1
    }

    floyd_warshall();

    cin >> s;
    for (int i = 1; i <= s; i++) {
        cin >> a >> b;
        if (dist[b][a] != INF) {
            cout << 1 << '\n';
        } else {
            if (dist[a][b] == INF) {
                cout << 0 << '\n';
            } else
                cout << -1 << '\n';
        }
    }
}