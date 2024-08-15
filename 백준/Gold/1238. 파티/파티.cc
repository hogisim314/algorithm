#include <iostream>
#include <queue>
#include <climits>
#include <vector>
using namespace std;

int N, M;
int X;
int u, v, w;

const int INF = INT_MAX;

const int MAX_V = 1005;
vector<pair<int, int> > Edges[MAX_V];//first가 거리
vector<pair<int, int> > Reverse_Edges[MAX_V];//first가 거리
vector<int> come(MAX_V, INF);
priority_queue<pair<int, int> > pq;
vector<int> go(MAX_V, INF);
int maxx = 0;

void Dijkstra_R(int start) {
	go[start] = 0;
	for (int i = 0; i < Reverse_Edges[start].size(); i++) {
		pq.push({-Reverse_Edges[start][i].second, Reverse_Edges[start][i].first });
	}
	while (!pq.empty()) {
		int weight = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (go[now] != INF) continue;
		go[now] = weight;
		for (int i = 0; i < Reverse_Edges[now].size(); i++) {
			if (go[Reverse_Edges[now][i].first] == INF) {
				pq.push({ -(Reverse_Edges[now][i].second + weight ), Reverse_Edges[now][i].first});
			}
		}
	}
}

void Dijkstra(int start) {
	come[start] = 0;
	for (int i = 0; i < Edges[start].size(); i++) {
		pq.push({ -Edges[start][i].second, Edges[start][i].first });
	}
	while (!pq.empty()) {
		int weight = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (come[now] != INF) continue;
		come[now] = weight;
		for (int i = 0; i < Edges[now].size(); i++) {
			if (come[Edges[now][i].first] == INF) {
				pq.push({ -(Edges[now][i].second + weight), Edges[now][i].first });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	cin >> X;
	for (int e = 1; e <= M; e++) {
		cin >> u >> v >> w;
		Edges[u].push_back({ v,w });
		Reverse_Edges[v].push_back({ u,w });
	}
	Dijkstra_R(X);
	Dijkstra(X);

	for (int i = 1; i <= N; i++) {
		int sum = go[i] + come[i];
		maxx = max(maxx, sum);
	}
	cout << maxx;
	return 0;
}