#include <limits.h>
#include <memory.h>

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n, m;
int a, b;
int dist[555][555];
int ans, cnt;
void floyd() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = 987654321;
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        dist[a][b] = 1;
    }
    floyd();

    for (int i = 1; i <= n; i++) {
        cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if (dist[i][j] != 987654321 || dist[j][i] != 987654321) {
                cnt++;
            }
        }
        // cout << "i " << i << " cnt " << cnt << '\n';
        if (cnt == n - 1) {
            ans++;
        }
    }
    cout << ans;
}