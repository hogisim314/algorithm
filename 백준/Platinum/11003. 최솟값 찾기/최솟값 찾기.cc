#include <algorithm>
#include <deque>
#include <iostream>
using namespace std;
int n, l;
int arr[5'111'111];
deque<pair<int, int> > dq;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> l;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	dq.push_back({ arr[1] ,1});
	cout << dq.front().first << ' ';
	for (int i = 2; i <= n; i++) {
		//넣고

		if (arr[i] >= dq.front().first) {
			int index = dq.size() - 1;
			while (index>=0 && dq[index].first > arr[i]) {
				dq.pop_back();
				index--;
			}
			dq.push_back({ arr[i], i });
		}
		else if (arr[i] < dq.front().first) {
			while (!dq.empty()) {
				dq.pop_back();
			}
			dq.push_back({ arr[i], i });
		}
		

		//빼기

		if (i>l) {
			if (dq.front().second == i - l) {
				dq.pop_front();
			}
		}
		cout << dq.front().first << ' ';
	}
}