#include<iostream>
#include<stdio.h>
using namespace std;

int n, m;
int parent[1000001];

int find_node(int now) {
	if (parent[now] == now) {
		return now;
	}
	else {
		return parent[now] = find_node(parent[now]);
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int cmd, a, b;
		scanf("%d %d %d", &cmd, &a, &b);

		if (cmd == 0) {
			int aRoot = find_node(a);
			int bRoot = find_node(b);
			parent[bRoot] = aRoot;
		}

		if (cmd == 1) {
			int visited[1000001] = { 0, };
			if (find_node(b) == find_node(a)) {
				printf("YES\n");
			}
			else {
				printf("NO\n");
			}
		}
	}
	return 0;
}