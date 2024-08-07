#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>
using namespace std;

typedef struct Data {
	int idx;
	int val;
};

int arr[1000001];
Data vec[1000001];
int parent[1000001];
stack<int> st;
int n, ans;

int search_position(int st, int ed, int val) {
	
	if (st == ed) {
		return st;
	}
	int piv = (st + ed) / 2;
	if (vec[piv].val < val) return search_position(piv + 1, ed, val);
	else if (vec[piv].val > val) return search_position(st, piv, val);
	else return piv;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);

	vec[0] = { 0, -2000000000 };

	for (int i = 1; i <= n; i++) {
		if (vec[ans].val < arr[i]) {
			parent[i] = vec[ans].idx;
			vec[++ans] = { i, arr[i] };
		}
		else {
			int pos = search_position(1, ans, arr[i]);
			vec[pos] = { i, arr[i] };
			parent[i] = vec[pos - 1].idx;
		}
	}

	cout << ans << endl;
	int now = vec[ans].idx;

	while (now != 0) {
		st.push(arr[now]);
		now = parent[now];
	}

	while (!st.empty()) {
		printf("%d ", st.top());
		st.pop();
	}

	cout << endl;
}