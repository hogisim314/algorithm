#include <bits/stdc++.h>
using namespace std;

int V, E;
int A, B, C;

const int MAX_V = 10'004;
priority_queue<pair<int, pair<int, int>> > pq;

int parent[MAX_V];
int Find(int x) {
	if (x == parent[x]) {
		return x;
	}
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	parent[Find(x)] = Find(y);
}

int Kruskal(void) {
	int dab = 0;
	while (!pq.empty())
	{
		int u = pq.top().first;
		int v = pq.top().second.first;
		int w = pq.top().second.second;
		pq.pop();
		if (Find(v) == Find(w)) 
		{
			continue;
		}
		else 
		{
			dab += -u;
			Union(v, w);
		}
	}
	return dab;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> V >> E;
	for (int v = 1; v <= V; v++) {
		parent[v] = v;
	}
	for (int e = 1; e <= E; e++) {
		cin >> A >> B >> C;
		pq.push({ -C,{A,B} });
	}
	cout << Kruskal() << '\n';
}