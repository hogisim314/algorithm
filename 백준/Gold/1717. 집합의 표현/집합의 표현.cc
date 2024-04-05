#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1'000'006;

int parent[MAX_N];

int Find(int x) {
	if (x == parent[x]) {
		return x;
	}
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	parent[Find(x)] = Find(y);
}

int N, M;
int _01, a, b;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int n = 1; n <= N; n++) {
		parent[n] = n;
	}
	for (int m = 1; m <= M; m++) {
		cin >> _01 >> a >> b;
		if (_01 == 0) {
			Union(a, b);
		}
		else {
			if (Find(a) == Find(b)) {
				cout << "YES" << '\n';
			}
			else {
				cout << "NO" << '\n';
			}
		}
	}
}