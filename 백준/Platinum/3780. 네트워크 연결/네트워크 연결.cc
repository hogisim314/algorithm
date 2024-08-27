#include <memory.h>

#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int t, n;
char cmd;
int i, j;
int parent[20100];
int dist[20100];  // 자기 클러스터 센터까지의 거리

int Find(int u) {
    if (u == parent[u]) {
        return u;
    }
    return parent[u] = Find(parent[u]);
}

int Find_Dist(int u) {
    if (u == parent[u]) return 0;
    return dist[u] = dist[u] + Find_Dist(parent[u]);
}

void Union(int u, int v) {
    parent[u] = v;
    dist[u] = abs(u - v) % 1000;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        cin >> n;
        // 최적화
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            dist[i] = 0;
        }

        while (true) {
            cin >> cmd;
            if (cmd == 'O') break;
            if (cmd == 'E') {
                cin >> i;
                // 쿼리가 들어올 떄 dist 경로압축
                Find_Dist(i);
                Find(i);
                cout << dist[i] << '\n';
            } else if (cmd == 'I') {
                cin >> i >> j;
                Union(i, j);
            }
        }
    }
}