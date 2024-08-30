#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;
int n, m, k;
int u, v, w;
int core;
int parent[1111];
set<int> coreSet;
priority_queue<pair<int, pair<int, int> > > pq;
int sum;
int weight, v1, v2;

int Find(int u) {
    if (u == parent[u]) {
        return u;
    }
    return parent[u] = Find(parent[u]);
}

void Union(int u, int v, int w) {
    int ancestoru = Find(u);
    int ancestorv = Find(v);
    bool isCoreSetU = coreSet.find(ancestoru) != coreSet.end();
    bool isCoreSetV = coreSet.find(ancestorv) != coreSet.end();

    if (isCoreSetU && isCoreSetV) return;
    sum += w;
    if (isCoreSetU) {
        parent[ancestorv] = ancestoru;
    } else {
        parent[ancestoru] = ancestorv;
    }
}

void MST() {
    while (!pq.empty()) {
        weight = -pq.top().first;
        v1 = pq.top().second.first;
        v2 = pq.top().second.second;

        pq.pop();

        if (Find(v1) != Find(v2)) {
            Union(v1, v2, weight);
        } else {
            continue;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    for (int i = 1; i <= k; i++) {
        cin >> core;
        coreSet.insert(core);
    }
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        pq.push(make_pair(-w, make_pair(u, v)));
    }
    MST();
    cout << sum;
}