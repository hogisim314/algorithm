#include <algorithm>
#include <iostream>
using namespace std;
int n, k;
int ans = 1;
int main() {
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        ans *= (n - i);
    }
    for (int i = k; i >= 1; i--) {
        ans /= i;
    }
    cout << ans;
}