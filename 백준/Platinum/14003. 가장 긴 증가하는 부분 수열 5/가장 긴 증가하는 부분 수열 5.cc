#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[1000001];
vector<int> v;
int vector_idx[1000001];//vector_idx[i]는 arr[i]가 vector에 들어간 idx값.
int ans[1000001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	v.push_back(arr[0]);
	vector_idx[0] = 0;
	for (int i = 1; i < n; i++) {
		int back = v.back();
		if (arr[i] > back) {
			v.push_back(arr[i]);
			vector_idx[i] = v.size()-1;
		}
		else {
			int k = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
			v[k] = arr[i];
			vector_idx[i] = k;
		}
	}
	cout << v.size()<< '\n';
	int k = v.size()-1;
	for (int i = n-1; i >= 0; i--) {
		if (vector_idx[i] == k) {
			ans[k] = arr[i]; k--;
		}
	}
	for (int i = 0; i < v.size(); i++) {
		cout << ans[i] << ' ';
	}
}