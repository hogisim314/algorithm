#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;

int n;
ll arr[100001];
vector<pair<ll, pair<ll, ll>> > v;
int b_search(int start, int end, int key);
void compare(int left, int right, int key);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	if (arr[0] > 0) {//산성용액일 경우
		cout << arr[0] << ' ' << arr[1];
		return 0;
	}
	else if (arr[n - 1] < 0) {//알칼리성 용액일 경우
		cout << arr[n - 2] << ' ' << arr[n - 1];
		return 0;
	}
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			int right = b_search(i + 1, n - 1, -arr[i]);
			v.push_back({ arr[i] + arr[right],{ arr[i],arr[right] } });
		}
		else if (i == 1) {
			int left = 0;
			int right = b_search(i + 1, n - 1, -arr[i]);
			compare(left, right, -arr[i]);
		}
		else if (i == n - 2) {
			int left = b_search(0, i - 1, -arr[i]);
			int right = n - 1;
			compare(left, right, -arr[i]);
		}
		else if (i == n - 1) {
			int left = b_search(0, i - 1, -arr[i]);
			v.push_back({ arr[i] + arr[left], { arr[left], arr[i]} });
		}
		else {
			int left = b_search(0, i - 1, -arr[i]);
			int right = b_search(i + 1, n - 1, -arr[i]);
			compare(left, right, -arr[i]);
		}

	}
	sort(v.begin(), v.end());
	if (v[0].first > 0) {
		cout << v[0].second.first << ' ' << v[0].second.second;
		return 0;
	}
	else if (v[n - 1].first < 0) {
		cout << v[n - 1].second.first << ' ' << v[n - 1].second.second;
		return 0;
	}
	int diff = -987654321;
	for (int i = 0; i < v.size()-1; i++) {
		if (v[i].first == 0) {
			cout << v[i].second.first << ' ' << v[i].second.second;
			return 0;
		}
		if (v[i].first < 0 && v[i + 1].first>0) {
			if (abs(v[i].first) >= v[i + 1].first) {
				cout << v[i + 1].second.first << ' ' << v[i + 1].second.second<<'\n';
				return 0;
			}
			else {
				cout << v[i].second.first << ' ' << v[i].second.second<<'\n';
				return 0;
			}
		}
	}
}

int b_search(int start, int end, int key) {
	if (end == start) {
		return end;
	}
	if (end-start==1) {
		if (abs(arr[start] - key) > abs(arr[end] - key)) {
			return end;
		}
		else return start;
	}
	int mid = (start + end) / 2;
	if (arr[mid] == key) {
		return mid;
	}
	if (key < arr[mid]) {
		return b_search(start, mid, key);
	}
	else if (arr[mid] < key) {
		return b_search(mid, end, key);
	}
}

void compare(int left, int right, int key) {
	if (key - arr[left] > arr[right] - key) {
		v.push_back({ -key + arr[right], { -key,arr[right] } });
	}
	else {
		v.push_back({ -key + arr[left], { arr[left],-key} });
	}
}