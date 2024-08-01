#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#define MAX 1000000000
using namespace std;
int n, m;
int aarr[1111];
int barr[1111];
long long gcd = 1;
void prime_factorization(int p, map<int, int> &m) {
    int n = p;
    for (int i = 2; i * i <= n; i++) {
        while (p % i == 0) {
            m[i]++;
            p /= i;
        }
    }
    m[p]++;
    return;
}

map<int, int> ma;
map<int, int> mb;
map<int, int> soinsoo;
string ans;
bool isBig = false;

long long get_pow(int p, int q) {
    long long ret = 1;
    if (q == 0) return 1;
    for (int i = 1; i <= q; i++) {
        ret *= p;
        if (ret > MAX) ret %= MAX;
    }
    return ret;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> aarr[i];
        prime_factorization(aarr[i], ma);
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> barr[i];
        prime_factorization(barr[i], mb);
    }
    for (auto itr = ma.begin(); itr != ma.end(); itr++) {
        int min_power = min(itr->second, mb[itr->first]);
        soinsoo[itr->first] = min_power;
    }
    for (auto itr = soinsoo.begin(); itr != soinsoo.end(); itr++) {
        gcd *= (long long)get_pow(itr->first, itr->second);
        if (gcd >= MAX) isBig = true;
        gcd %= MAX;
    }
    if (isBig) {
        printf("%09d", gcd);
        return 0;
    }
    cout << gcd;
}