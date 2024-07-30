#include<iostream>
#define ll long long
using namespace std;
ll arr[111111];
ll n, s;
ll startt = 1, endd = 1;
ll sum, len, cnt, minn = 111111;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> s;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	while (startt <= n) {
		if (sum >= s) {
			len = endd - startt;
			cnt++;
			minn = min(minn, len);
			sum -= arr[startt++];
		}
		else if (sum < s) {
			sum += arr[endd++];
			if (endd > n + 1) break;
		}
	}
	if (cnt) cout << minn;
	else cout << 0;
}