#include <memory.h>

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define MAX_LEV 15
int tc;
int n;
int a, b, root;

int indegree[10100];
vector<int> nodes[10100];
int parent[10100][15];
int level[10100];

int lca(int u, int v) {
    if (level[u] < level[v]) swap(u, v);
    int diff = level[u] - level[v];
    for (int i = 0; diff != 0; i++) {
        if (diff % 2) {
            u = parent[u][i];
        }
        diff /= 2;
    }

    if (u != v) {
        for (int i = MAX_LEV - 1; i >= 0; i--) {
            if (parent[u][i] != -1 && parent[u][i] != parent[v][i]) {
                u = parent[u][i];
                v = parent[v][i];
            }
        }
        u = parent[u][0];
    }

    return u;
}

void connection() {
    for (int k = 1; k < MAX_LEV; k++) {
        for (int i = 1; i <= n; i++) {
            parent[i][k] = parent[parent[i][k - 1]][k - 1];
        }
    }
}

void dfs(int cur) {
    for (auto adj : nodes[cur]) {
        if (level[adj] == -1) {
            parent[adj][0] = cur;
            level[adj] = level[cur] + 1;
            dfs(adj);
        }
    }
}

int main() {
    cin >> tc;
    while (tc--) {
        memset(indegree, 0, sizeof(indegree));
        memset(nodes, 0, sizeof(nodes));
        memset(parent, -1, sizeof(parent));
        cin >> n;
        fill(level, level + n + 1, -1);
        for (int i = 1; i <= n - 1; i++) {
            cin >> a >> b;
            nodes[a].push_back(b);
            nodes[b].push_back(a);
            indegree[b]++;
        }
        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0) {
                root = i;
                break;
            }
        }
        level[root] = 0;
        dfs(root);
        connection();

        cin >> a >> b;  // LCA찾아야할 노드
        cout << lca(a, b) << '\n';
    }
}