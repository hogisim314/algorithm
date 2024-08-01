#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int n;
int cnt;
int s = 1, e = 1, sum = 0;
int arr[4000001];
int main() {
	cin >> n;

	for (int i = 2; i <= n; i++) {
		arr[i] = i;
	}

	for (int i = 2; i <= sqrt(n); i++) {
		if (arr[i] == 0) continue;

		for (int j = i * i; j <= n; j += i) {
			arr[j] = 0;
		}
	}
	vector<int> primeNum;
	primeNum.push_back(0);
	for (int i = 2; i <= n; i++) {
		if (arr[i] != 0) primeNum.push_back(arr[i]);
	}
	int len = primeNum.size() - 1;

	while (s <= len) {
		if (sum == n) {
			cnt++;
			if (e > len) break;
			sum -= primeNum[s++];
		}
		else if (sum < n) {
			if (e > len) break;
			sum += primeNum[e++];

		}
		else if (sum > n) {
			sum -= primeNum[s++];
		}
	}
	cout << cnt;

}