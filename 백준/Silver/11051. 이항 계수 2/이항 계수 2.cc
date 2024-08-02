#include <iostream>
#include <vector>
#define mod 10007
using namespace std;
const int max_num = 1000;
bool not_prime[max_num + 1];
int combination[max_num + 1][max_num + 1];
int gcd(int a, int b);
void sieve();
void prime_factorization(int n);
int Combination(int n, int k);
void init();
int n, k, cnt;


int main() {
	cin >> n >> k;
	init();
	cout << combination[n][k];
}

int gcd(int a, int b) {
	if (b > a) return gcd(b, a);
	if (!b) return a;
	else return gcd(b, a % b);
}

void sieve() {
	for (int i = 2; i < n + 1; i++) {
		if (!not_prime[i]) {
			for (int j = 2 * i; j <= n; j += i) {
				not_prime[j] = true;
			}
		}
	}
}

void prime_factorization(int n) {
	int p = 2;
	vector<pair<int, int> > v;
	while (n != 1) {
		if (!not_prime[p]) {//p가 소수라면
			if (n % p == 0) {
				int tmp = 0;
				while (n % p == 0) {
					tmp++;
					n /= p;
				}
				v.push_back({ p,tmp });
			}
		}
		p++;
		if (p * p > n && n != 1) {
			v.push_back({ n,1 });
			break;
		}
	}
	for (auto pii : v) {
		cout << pii.first << ' ' << pii.second << '\n';
	}
}

int Combination(int n, int k) {//조합 정의 계산식 이용
	int ret = 1;
	for (int i = n - k + 1; i <= n; i++) {
		ret *= i;
	}
	for (int i = 1; i <= k; i++) {
		ret /= i;
	}
	return ret;
}

void init() {
	for (int i = 1; i <= max_num; i++) {
		for (int j = 0; j <= i; j++) {
			if (!j || j == i) combination[i][j] = 1;
			else combination[i][j] = (combination[i - 1][j - 1] + combination[i - 1][j])%mod;
		}
	}
}