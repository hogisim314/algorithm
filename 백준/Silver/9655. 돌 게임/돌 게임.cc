#include <algorithm>
#include <iostream>
using namespace std;
int n;
bool dp[1111];  // 상근이가 이기면 true
int main() {
    cin >> n;
    dp[1] = true;
    dp[2] = false;
    dp[3] = true;
    dp[4] = false;
    for (int i = 5; i <= n; i++) {
        if (dp[i - 3] == false || dp[i - 1] == false) {
            dp[i] = true;
        } else
            dp[i] = false;
    }
    if (dp[n]) {
        cout << "SK";
    } else
        cout << "CY";
}