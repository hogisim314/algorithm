#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n, m;
int a, b;
int parent[50500];
int level[50500];
vector<int> nodes[50500];
bool visited[50500];

int lca(int p, int q) {
    if (level[p] < level[q]) {
        swap(p, q);
    }

    while (level[p] != level[q]) {
        p = parent[p];
    }

    while (p != q) {
        p = parent[p];
        q = parent[q];
    }
    return p;
}

void make_tree(int cur, int depth) {
    level[cur] = depth;
    visited[cur] = true;

    for (int i = 0; i < nodes[cur].size(); i++) {
        int temp = nodes[cur][i];
        if (visited[temp]) continue;
        parent[temp] = cur;
        make_tree(temp, depth + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        level[i] = 1;
    }
    for (int i = 1; i <= n - 1; i++) {
        cin >> a >> b;
        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }

    make_tree(1, 1);
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        // cout << a << ' ' << b << ' ' << level[a] << ' ' << level[b] << '\n';
        cout << lca(a, b) << '\n';
    }
}