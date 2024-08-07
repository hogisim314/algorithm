#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int n, m;

struct Data {
	int idx;
	int in_degree;
};

queue<int> q;
vector<int> adj[100001];
int inner_degree[100001];

int main()
{
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		adj[a].push_back(b);
		inner_degree[b]++;
	}

	for (int i = 0; i < n; i++) {
		if (inner_degree[i + 1] == 0)
		{
			q.push(i+1);
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", q.front());
		for (int j = 0; j < adj[q.front()].size(); j++) {
			inner_degree[adj[q.front()][j]]--;
			if (inner_degree[adj[q.front()][j]] == 0) {
				q.push(adj[q.front()][j]);
			}
		}
		q.pop();
	}

	return 0;
}