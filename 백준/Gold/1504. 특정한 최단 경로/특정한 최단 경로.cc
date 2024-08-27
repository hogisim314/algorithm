#include <iostream>
#include <queue>
#include <climits>
#include <vector>
using namespace std;

long long N, E;
long long a, b, c;
long long v1, v2;
long long road_1_v1;
long long road_1_v2;
long long road_v1_v2;
long long road_v1_N;
long long road_v2_v1;
long long road_v2_N;
long long firstroad;
long long secondroad;
const long long INF = LLONG_MAX;

const long long MAX_V = 805;
vector<pair<long long, long long> > Edges[MAX_V];//first가 거리
vector<long long> dist(MAX_V, INF);
priority_queue<pair<long long, long long> > pq;
long long maxx = 0;

void Dijkstra(long long start);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> E;
	for (long long e = 1; e <= E; e++) {
		cin >> a >> b >> c;
		Edges[a].push_back({b,c });
		Edges[b].push_back({ a,c });
	}
	cin >> v1 >> v2;

	Dijkstra(1);
	road_1_v1 = dist[v1];
	road_1_v2 = dist[v2];

	for (long long i = 0; i < dist.size(); i++) {
		dist[i] = INF;
	}
	Dijkstra(v1);
	road_v1_v2 = dist[v2];
	road_v1_N = dist[N];

	for (long long i = 0; i < dist.size(); i++) {
		dist[i] = INF;
	}
	Dijkstra(v2);
	road_v2_v1 = dist[v1];
	road_v2_N = dist[N];
	
	//check road 1->v1->v2->E
	if (road_1_v1 != INF && road_v1_v2 != INF && road_v2_N != INF) {
		firstroad += road_1_v1;
		firstroad += road_v1_v2;
		firstroad += road_v2_N;
	}

	if (road_1_v2 != INF && road_v2_v1 != INF && road_v1_N != INF) {
		secondroad += road_1_v2;
		secondroad += road_v2_v1;
		secondroad += road_v1_N;
	}

	//1->v1->v2->n
	//1->v2->v1->n
	if (firstroad != 0 && secondroad != 0) {
		cout << min(firstroad, secondroad);
	}
	else cout << -1;
	return 0;
}

void Dijkstra(long long start) {
	dist[start] = 0;
	for (long long i = 0; i < Edges[start].size(); i++) {
		pq.push({ -Edges[start][i].second, Edges[start][i].first });
	}
	while (!pq.empty()) {
		long long weight = -pq.top().first;
		long long now = pq.top().second;
		pq.pop();
		if (dist[now] != INF) continue;
		dist[now] = weight;
		for (long long i = 0; i < Edges[now].size(); i++) {
			if (dist[Edges[now][i].first] == INF) {
				pq.push({ -(Edges[now][i].second + weight), Edges[now][i].first });
			}
		}
	}
}