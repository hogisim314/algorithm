#include <algorithm>
#include <iostream>
using namespace std;
int n, m;
int arr[111111];
int parr[111111];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        parr[i] = parr[i - 1] + arr[i];
    }
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        cout << parr[b] - parr[a - 1] << '\n';
    }
}