#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
#define MAX 1000000
int n;
bool sieve[1000100];
set<int> sosoo;

void get_sieve() {
    sieve[0] = sieve[1] = true;
    for (int i = 2; i * i <= MAX; i++) {
        if (sieve[i] == false) {
            for (int j = i * i; j <= MAX; j += i) {
                if (j > MAX) continue;
                sieve[j] = true;
            }
        }
    }
    for (int i = 3; i <= MAX; i++) {
        if (!sieve[i]) {
            sosoo.insert(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    get_sieve();
    while (true) {
        cin >> n;
        if (n == 0) break;
        int left = 3;
        int right = n - 3;
        bool found = false;
        while (left <= right) {
            if (!sieve[left] && !sieve[right]) {
                cout << n << " = " << left << " + " << right << '\n';
                found = true;
                break;
            }
            left += 2;
            right -= 2;
        }
        if (found) {
            continue;
        } else {
            cout << "Goldbach's conjecture is wrong." << '\n';
        }
    }
    return 0;
}
// bool found = false;
// for (auto itr = sosoo.begin(); itr != sosoo.end(); itr++) {
//     if (*itr > n / 2) {
//         break;
//     }
//     if (sosoo.find(n - *itr) != sosoo.end()) {
//         cout << n << " = " << *itr << " + " << n - *itr << '\n';
//         found = true;
//         break;
//     }
// }
// if (found) {
//     continue;
// } else {
//     cout << "Goldbach's conjecture is wrong." << '\n';
// }