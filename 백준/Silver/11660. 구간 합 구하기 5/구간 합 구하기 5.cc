#include <algorithm>
#include <iostream>
using namespace std;
int n, m;
int arr[1111][1111];
long long psum[1111][1111];
int a, b, c, d;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
            psum[i][j] = psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1] +
                         arr[i][j];
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cout << psum[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    for (int i = 1; i <= m; i++) {
        cin >> a >> b >> c >> d;
        cout << psum[c][d] - psum[a - 1][d] - psum[c][b - 1] +
                    psum[a - 1][b - 1]
             << '\n';
    }
}