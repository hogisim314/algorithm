#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int V, E, A, B, C;
int weight;
int v1, v2;
int parent[10100];
long long ans;
priority_queue<pair<int, pair<int, int>>> pq;

int Find(int u) {
    if (parent[u] == u) return u;
    return parent[u] = Find(parent[u]);
}

void Union(int u, int v) {
    int pu = Find(u);
    int pv = Find(v);

    if (pu == pv) return;
    parent[pu] = pv;
}

void MST() {
    while (!pq.empty()) {
        weight = -pq.top().first;
        v1 = pq.top().second.first;
        v2 = pq.top().second.second;

        pq.pop();

        if (Find(v1) != Find(v2)) {
            ans += weight;
            Union(v1, v2);
        } else
            continue;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> V >> E;
    for (int i = 1; i <= V; i++) {
        parent[i] = i;
    }
    for (int i = 1; i <= E; i++) {
        cin >> A >> B >> C;
        pq.push(make_pair(-C, make_pair(A, B)));
    }
    MST();
    cout << ans;
}