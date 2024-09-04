#include <algorithm>
#include <iostream>
using namespace std;
int tc;
int n, k;
int arr[55];
int minDIff = 2147000000;
int main() {
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cin >> n >> k;
        minDIff = 2147000000;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }

        sort(arr + 1, arr + n + 1);
        for (int i = 1; i <= n - k + 1; i++) {
            minDIff = min(minDIff, arr[i + k - 1] - arr[i]);
        }
        cout << "#" << t << ' ' << minDIff << '\n';
    }
}