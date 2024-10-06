#include <limits.h>

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n, e;
int a, b, c;
int v1, v2;
vector<pair<int, int> > nodes[888];
int dist[888];
int adj, weight;
int cur;
int ans1, ans2;

void debug() {
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << ' ';
    }
    cout << '\n';
}

void init() {
    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
    }
}

void Dijkstra(int st) {
    priority_queue<pair<int, int> > pq;
    dist[st] = 0;
    for (int i = 0; i < nodes[st].size(); i++) {
        adj = nodes[st][i].first;
        weight = nodes[st][i].second;
        pq.push(make_pair(-weight, adj));
    }

    while (!pq.empty()) {
        weight = -pq.top().first;
        cur = pq.top().second;
        pq.pop();
        if (dist[cur] != INT_MAX) continue;
        dist[cur] = weight;
        for (int i = 0; i < nodes[cur].size(); i++) {
            adj = nodes[cur][i].first;
            weight = nodes[cur][i].second;
            if (dist[adj] > dist[cur] + weight) {
                pq.push(make_pair(-(dist[cur] + weight), adj));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> e;
    for (int i = 1; i <= e; i++) {
        cin >> a >> b >> c;
        nodes[a].push_back(make_pair(b, c));
        nodes[b].push_back(make_pair(a, c));
    }
    cin >> v1 >> v2;

    init();
    Dijkstra(1);
    if (dist[v1] == INT_MAX || dist[v2] == INT_MAX) {
        cout << -1;
        return 0;
    }
    ans1 += dist[v1];
    ans2 += dist[v2];

    init();
    Dijkstra(v1);
    if (dist[v2] == INT_MAX || dist[n] == INT_MAX) {
        cout << -1;
        return 0;
    }
    ans1 += dist[v2];
    ans2 += dist[n];

    init();
    Dijkstra(v2);
    if (dist[n] == INT_MAX || dist[v1] == INT_MAX) {
        cout << -1;
        return 0;
    }
    ans1 += dist[n];
    ans2 += dist[v1];

    cout << min(ans1, ans2);
}

// 1->v1->v2->N
// 1->v2->v1->N