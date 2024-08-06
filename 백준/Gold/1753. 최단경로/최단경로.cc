#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int V, E;
int K;
int u, v, w;

const int INF = INT_MAX;

const int MAX_V = 20'005;
vector<pair<int, int> > Edges[MAX_V];  // first가 거리
vector<int> dist(MAX_V, INF);
priority_queue<pair<int, int> > pq;

void Dijkstra(int start) {
    int weight, dest;
    for (int i = 0; i < Edges[start].size(); i++) {
        dest = Edges[start][i].first;
        weight = Edges[start][i].second;
        pq.push(make_pair(-weight, dest));
    }

    while (!pq.empty()) {
        weight = -pq.top().first;
        dest = pq.top().second;
        pq.pop();
        if (dist[dest] != INF) continue;
        dist[dest] = weight;
        for (int i = 0; i < Edges[dest].size(); i++) {
            if (dist[Edges[dest][i].first] == INF) {
                pq.push(make_pair(-(dist[dest] + Edges[dest][i].second),
                                  Edges[dest][i].first));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> V >> E;
    cin >> K;
    for (int i = 1; i <= E; i++) {
        cin >> u >> v >> w;
        Edges[u].push_back(make_pair(v, w));
    }
    dist[K] = 0;
    Dijkstra(K);
    for (int i = 1; i <= V; i++) {
        if (i == K) {
            cout << 0 << '\n';
        } else {
            if (dist[i] == INF) {
                cout << "INF" << '\n';
            } else
                cout << dist[i] << '\n';
        }
    }
}