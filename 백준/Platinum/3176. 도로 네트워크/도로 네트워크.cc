#include <limits.h>
#include <memory.h>

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define MAX_LEV 18
typedef long long ll;
int n, m;
int a, b, d, root;

vector<pair<int, ll> > nodes[100100];
int parent[100100][MAX_LEV];
int mindist[100100][MAX_LEV];
int maxdist[100100][MAX_LEV];
int level[100100];
int MIN, MAX;

void lca(int u, int v) {
    ll sum = 0;
    MIN = 2000000;
    MAX = 0;
    if (level[u] < level[v]) swap(u, v);
    int diff = level[u] - level[v];
    for (int i = 0; diff != 0; i++) {
        if (diff % 2) {
            MIN = min(MIN, mindist[u][i]);
            MAX = max(MAX, maxdist[u][i]);
            u = parent[u][i];
        }
        diff /= 2;
    }

    if (u != v) {
        for (int i = MAX_LEV - 1; i >= 0; i--) {
            if (parent[u][i] != -1 && parent[u][i] != parent[v][i]) {
                MIN = min(MIN, mindist[u][i]);
                MIN = min(MIN, mindist[v][i]);
                MAX = max(MAX, maxdist[u][i]);
                MAX = max(MAX, maxdist[v][i]);
                u = parent[u][i];
                v = parent[v][i];
            }
        }
        MIN = min(MIN, mindist[u][0]);
        MIN = min(MIN, mindist[v][0]);
        MAX = max(MAX, maxdist[u][0]);
        MAX = max(MAX, maxdist[v][0]);
    }
}

void connection() {
    for (int k = 1; k < MAX_LEV; k++) {
        for (int i = 1; i <= n; i++) {
            parent[i][k] = parent[parent[i][k - 1]][k - 1];
            mindist[i][k] =
                min(mindist[i][k - 1], mindist[parent[i][k - 1]][k - 1]);
            maxdist[i][k] =
                max(maxdist[i][k - 1], maxdist[parent[i][k - 1]][k - 1]);
        }
    }
}

void dfs(int cur) {
    for (auto adj : nodes[cur]) {
        if (level[adj.first] == -1) {
            parent[adj.first][0] = cur;
            mindist[adj.first][0] = adj.second;
            maxdist[adj.first][0] = adj.second;
            level[adj.first] = level[cur] + 1;
            dfs(adj.first);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(nodes, 0, sizeof(nodes));
    memset(parent, -1, sizeof(parent));
    memset(mindist, INT_MAX, sizeof(mindist));
    memset(maxdist, INT_MIN, sizeof(maxdist));
    cin >> n;
    fill(level, level + n + 1, -1);
    for (int i = 1; i <= n - 1; i++) {
        cin >> a >> b >> d;
        nodes[a].push_back(make_pair(b, d));
        nodes[b].push_back(make_pair(a, d));
    }
    level[a] = 0;
    dfs(a);
    connection();
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;  // LCA찾아야할 노드
        lca(a, b);
        cout << MIN << ' ' << MAX << '\n';
    }
}