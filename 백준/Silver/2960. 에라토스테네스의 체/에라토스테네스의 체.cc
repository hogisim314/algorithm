#include <iostream>
#include <vector>
using namespace std;
const int max_num = 1000;
bool not_prime[max_num + 1];
int gcd(int a, int b);
void sieve();

int n, k, cnt;

int main() {
	cin >> n >> k;
	sieve();
}

int gcd(int a, int b) {
	if (b > a) return gcd(b, a);
	if (!b) return a;
	else return gcd(b, a % b);
}

void sieve() {
	for (int i = 2; i < n + 1; i++) {
		if (!not_prime[i]) {
			cnt++;
			if (cnt == k) {
				cout << i;
				return;
			}
		}
		if (!not_prime[i]) {
			for (int j = 2 * i; j <= n; j += i) {
				if (!not_prime[j]) {
					cnt++;
					if (cnt == k) {
						cout << j;
						return;
					}
					not_prime[j] = true;
				}
			}
		}
	}
}