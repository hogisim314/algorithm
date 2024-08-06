#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;

int n, m, tree_depth;
int parent[20][100001];
int depth[100001];
vector<int> adj[100001];
int visited[100001];
queue<pair<int, int>> q;

void cal_depth() {

	while (!q.empty()) {
		int now = q.front().first;
		visited[now] = 1;
		depth[q.front().first] = q.front().second;

		for (int i = 1; i < 19; i++) {
			if (parent[i - 1][now] == -1) break;
			parent[i][now] = parent[i - 1][parent[i - 1][now]];
		}

		for (int i = 0; i < adj[now].size(); i++) {
			if (visited[adj[now][i]] == 1) continue;
			parent[0][adj[now][i]] = now;
			q.push({ adj[now][i], q.front().second + 1 });
		}
		q.pop();
	}
	return;
}

int find_lca(int a, int b) {
	if (depth[a] > depth[b]) {
		while (depth[a] != depth[b]) {
			queue<int> query;
			int diff = depth[a] - depth[b];
			int cnt = 0;
			while (diff > 0) {
				if (diff % 2 == 1) {
					a = parent[cnt][a];
					cnt++;
				}
				diff /= 2;
			}
		}
	}
	else if (depth[a] < depth[b]) {
		while (depth[a] != depth[b]) {
			queue<int> query;
			int diff = depth[b] - depth[a];
			int cnt = 0;
			while (diff > 0) {
				if (diff % 2 == 1) {
					b = parent[cnt][b];
					cnt++;
				}
				diff /= 2;
			}
		}
	}

	if (a == b) return a;
	
	int cnt = 19;
	while (cnt>=0) {
		if (parent[cnt][a] != parent[cnt][b]) {
			a = parent[cnt][a];
			b = parent[cnt][b];
		}
		cnt--;
	}
	
	return parent[0][a];
}

int main() {

	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	while (1 << tree_depth < n) tree_depth++;

	scanf("%d",&m);
	q.push({ 1, 0 });
	cal_depth();

	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", find_lca(a, b));
	}
	return 0;
}