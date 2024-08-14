#include <memory.h>

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define MAX_LEV 17
int n, m;
int a, b;
int parent[100100][MAX_LEV];
int level[100100];
vector<int> nodes[100100];
bool visited[100100];
int temp;

int lca(int p, int q) {  // p가 더 깊다. 즉 level[p]가 더 큰걸로 간주할거임
    if (level[p] < level[q]) {
        swap(p, q);
    }

    // 정점 차이 구하자
    int diff = level[p] - level[q];
    for (int i = 0; diff != 0; i++) {
        if (diff % 2) {  // 만약 diff가 9라고 해보자. 1001(2)
            p = parent[p][i];
        }
        diff /= 2;
    }
    if (p != q) {
        for (int i = MAX_LEV - 1; i >= 0; i--) {
            if (parent[p][i] != -1 && parent[p][i] != parent[q][i]) {
                p = parent[p][i];
                q = parent[q][i];
            }
        }
        p = parent[p][0];
    }
    return p;
}

void connection() {
    for (int k = 1; k < MAX_LEV; k++) {
        for (int cur = 1; cur <= n; cur++) {
            parent[cur][k] = parent[parent[cur][k - 1]][k - 1];
        }
    }
    return;
}

void make_tree(int cur) {
    for (auto adj : nodes[cur]) {
        if (level[adj] == -1) {
            parent[adj][0] = cur;
            level[adj] = level[cur] + 1;
            make_tree(adj);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    memset(parent, -1, sizeof(parent));
    fill(level, level + n + 1, -1);
    level[1] = 0;

    for (int i = 1; i <= n - 1; i++) {
        cin >> a >> b;
        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }

    make_tree(1);
    connection();
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        // cout << a << ' ' << b << ' ' << level[a] << ' ' << level[b] << '\n';
        cout << lca(a, b) << '\n';
    }
}