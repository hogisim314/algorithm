#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string p;
int k;
bool sieve[1000100];  // false가 소수 true가 복합수

void get_sieve() {
    sieve[0] = sieve[1] = true;
    for (int i = 2; i * i <= 1000000; i++) {
        for (int j = i * i; j <= 1000000; j += i) {
            sieve[j] = true;
        }
    }
}

bool can_divide(int k) {  // 나뉘어진다는 말
    int sum = 0;
    for (int i = 0; i < p.size(); i++) {
        sum = (sum * 10 + (p[i] - '0')) % k;
    }

    return sum == 0;
}

int main() {
    get_sieve();
    cin >> p >> k;
    for (int i = 2; i < k; i++) {
        if (sieve[i]) continue;  // sieve[i]가 false여야 소수
        if (can_divide(i)) {
            cout << "BAD " << i;
            return 0;
        }
    }
    cout << "GOOD";
    return 0;
}