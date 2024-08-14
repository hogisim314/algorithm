#include <memory.h>

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define MAX_LEV 17
int n, m;
int a, b, d, root;

int indegree[40100];
vector<pair<int, int> > nodes[40100];
int parent[40100][MAX_LEV];
int dist[40100][MAX_LEV];
int level[40100];

int lca(int u, int v) {
    int sum = 0;
    if (level[u] < level[v]) swap(u, v);
    int diff = level[u] - level[v];
    for (int i = 0; diff != 0; i++) {
        if (diff % 2) {
            sum += dist[u][i];
            u = parent[u][i];
        }
        diff /= 2;
    }

    if (u != v) {
        for (int i = MAX_LEV - 1; i >= 0; i--) {
            if (parent[u][i] != -1 && parent[u][i] != parent[v][i]) {
                sum += dist[u][i];
                sum += dist[v][i];
                u = parent[u][i];
                v = parent[v][i];
            }
        }
        sum += dist[u][0];
        sum += dist[v][0];
        u = parent[u][0];
    }

    return sum;
}

void connection() {
    for (int k = 1; k < MAX_LEV; k++) {
        for (int i = 1; i <= n; i++) {
            parent[i][k] = parent[parent[i][k - 1]][k - 1];
            dist[i][k] = dist[i][k - 1] + dist[parent[i][k - 1]][k - 1];
        }
    }
}

void dfs(int cur) {
    for (auto adj : nodes[cur]) {
        if (level[adj.first] == -1) {
            parent[adj.first][0] = cur;
            dist[adj.first][0] = adj.second;
            level[adj.first] = level[cur] + 1;
            dfs(adj.first);
        }
    }
}

int main() {
    memset(indegree, 0, sizeof(indegree));
    memset(nodes, 0, sizeof(nodes));
    memset(parent, -1, sizeof(parent));
    cin >> n;
    fill(level, level + n + 1, -1);
    for (int i = 1; i <= n - 1; i++) {
        cin >> a >> b >> d;
        nodes[a].push_back(make_pair(b, d));
        nodes[b].push_back(make_pair(a, d));
    }
    level[1] = 0;
    dfs(1);
    connection();
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;  // LCA찾아야할 노드
        cout << lca(a, b) << '\n';
    }
}