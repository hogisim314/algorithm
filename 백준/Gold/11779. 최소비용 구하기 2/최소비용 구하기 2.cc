#include <limits.h>

#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
int n, m;
int u, v, w;
vector<pair<int, int> > nodes[1111];
int parent[1111];
int dist[1111];
int st, ed;
int prnt;
int weight, adj, cur;
void init() {
    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
    }
}

void dijkstra() {
    priority_queue<pair<pair<int, int>, int> > pq;
    pq.push(make_pair(make_pair(0, st), st));
    parent[st] = st;

    while (!pq.empty()) {
        weight = -pq.top().first.first;
        cur = pq.top().first.second;
        prnt = pq.top().second;
        pq.pop();
        if (dist[cur] != INT_MAX) continue;
        parent[cur] = prnt;
        dist[cur] = weight;

        for (int i = 0; i < nodes[cur].size(); i++) {
            weight = nodes[cur][i].second;
            adj = nodes[cur][i].first;
            if (dist[adj] > dist[cur] + weight) {
                pq.push(make_pair(make_pair(-(dist[cur] + weight), adj), cur));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    init();
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        nodes[u].push_back(make_pair(v, w));
    }
    cin >> st >> ed;
    dijkstra();
    cout << dist[ed] << '\n';
    stack<int> s;
    cur = ed;
    while (true) {
        s.push(cur);
        if (parent[cur] == cur) break;
        cur = parent[cur];
    }
    cout << s.size() << '\n';
    while (!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }
}