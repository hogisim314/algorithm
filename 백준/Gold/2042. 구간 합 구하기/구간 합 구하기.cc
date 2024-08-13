#include <iostream>
#include <algorithm>
#include <vector>
#include<cmath>
using namespace std;
long long n, m, k;
int tree_size, h;


long long init(vector<long long> &arr, vector<long long> &tree, long long node, long long start, long long end) {
	if (start == end)
		return tree[node] = arr[start];

	long long mid = (start + end) / 2;

	return tree[node] = init(arr, tree, node * 2, start, mid) + init(arr, tree, node * 2 + 1, mid + 1, end);
}

long long sum(vector<long long> &tree, long long node, long long start, long long end, long long left, long long right) {
	if (left > end || right < start) return 0;

	if (left <= start && end <= right) return tree[node];

	long long mid = (start+end) / 2;
	return sum(tree, node * 2, start, mid, left, right) + sum(tree, node * 2 + 1, mid + 1, end, left, right);
}

void update(vector<long long> &tree, long long node, long long start, long long end, long long index, long long diff) {//diff = val - tree[index]
	if (index<start || index>end) return;
	tree[node] = tree[node] + diff;

	if (start != end) {
		long long mid = (start + end) / 2;
		update(tree, node * 2, start, mid, index, diff);
		update(tree, node * 2 + 1, mid + 1, end, index, diff);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	h = (int)ceil(log2(n));
	vector<long long> arr(n);
	tree_size = (1 << (h + 1));
	vector<long long> tree(tree_size);
	for (int i = 0; i <= n-1; i++) {
		long long num;
		cin >> num;
		arr[i] = num;
	}

	init(arr, tree, 1,0,n-1);

	for (int i = 0; i < m+k; i++) {
		long long a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {//update
			b--;
			long long diff = c - arr[b];
			arr[b] = c;
			update(tree, 1, 0,n-1 , b,diff);
		}
		else if (a == 2) {//sum
			cout << sum(tree, 1,0,n-1, b-1, c-1) << '\n';
		}
	}
}