#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;
vector<int> adj[1111];
queue<int> bfs;
bool visited[1111];
int main() {//bd fs 
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int vertex, edge, from, to, start;
	cin >> vertex >> edge;
	for (int i = 0; i < edge; i++) {
		cin >> from >> to;
		adj[from].push_back(to);
		adj[to].push_back(from);
	}
	for (int i = 1; i <= edge; i++) {
		sort(adj[i].begin(), adj[i].end());
	}
	bfs.push(1);
	visited[1] = 1;
	int cnt = 0;
	while (!bfs.empty()) {
		int now = bfs.front();
		bfs.pop();
		for (int i = 0; i < adj[now].size(); i++) {
			if (!visited[adj[now][i]]) {
				bfs.push(adj[now][i]);
				visited[adj[now][i]] = 1;
				cnt++;
			}
		}
	}
	cout << cnt;


	return 0;
}