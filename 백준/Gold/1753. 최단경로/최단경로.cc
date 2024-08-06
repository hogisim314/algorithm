#include <iostream>
#include <queue>
#include <climits>
#include <vector>
using namespace std;

int V, E;
int K;
int u, v, w;

const int INF = INT_MAX;

const int MAX_V = 20'005;
vector<pair<int, int> > Edges[MAX_V];//first가 거리
vector<int> dist(MAX_V, INF);
priority_queue<pair<int, int> > pq;

void Dijkstra(int start) {
	dist[start] = 0;
	for (int i = 0; i < Edges[start].size(); i++) {
		pq.push({-Edges[start][i].second, Edges[start][i].first });
	}
	while (!pq.empty()) {
		int weight = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (dist[now] != INF) continue;
		dist[now] = weight;
		for (int i = 0; i < Edges[now].size(); i++) {
			if (dist[Edges[now][i].first] == INF) {
				pq.push({ -(Edges[now][i].second + weight ), Edges[now][i].first});
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> V >> E;
	cin >> K;
	for (int e = 1; e <= E; e++) {
		cin >> u >> v >> w;
		Edges[u].push_back({ v,w });
	}
	Dijkstra(K);

	for (int v = 1; v <= V; v++) {
		if (dist[v] == INF)
		{
			cout << "INF" << '\n';
		}
		else {
			cout << dist[v] << '\n';
		}
	}
	return 0;
}