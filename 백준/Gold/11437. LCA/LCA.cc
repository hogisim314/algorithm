#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int N, M;
int parent[50100];
int level[50100];
vector<int> nodes[50100];
bool visited[50100];
int root = 1;
int u, v;

int lca(int v1, int v2) {
    if (level[v1] < level[v2]) swap(v1, v2);

    while (level[v1] != level[v2]) {
        v1 = parent[v1];
    }
    while (v1 != v2) {
        v1 = parent[v1];
        v2 = parent[v2];
    }
    return v1;
}

void make_tree(int node, int depth) {
    level[node] = depth;
    visited[node] = true;
    for (int i = 0; i < nodes[node].size(); i++) {
        int child = nodes[node][i];
        if (visited[child]) continue;
        parent[child] = node;
        level[child] = depth + 1;
        make_tree(child, depth + 1);
    }
}

int main() {
    cin >> N;
    for (int i = 1; i <= N - 1; i++) {
        cin >> u >> v;
        nodes[u].push_back(v);
        nodes[v].push_back(u);
    }
    make_tree(1, 1);
    cin >> M;
    for (int i = 1; i <= M; i++) {
        cin >> u >> v;
        cout << lca(u, v) << '\n';
        ;
    }
}