#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
int n, h;
int arr[200200];
vector<int> a;
vector<int> b;
int MIN = 2100000000;
int ans;
int cnt;
int main() {
    cin >> n >> h;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        if (i % 2 == 1) {  // 석순 아래서부터 위로
            a.push_back(arr[i]);
        } else {  // 종유석 위에서 아래롤
            b.push_back(arr[i]);
        }
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for (int i = 1; i <= h; i++) {
        cnt = 0;
        cnt += (n / 2) - (lower_bound(a.begin(), a.end(), i) - a.begin());
        cnt +=
            (n / 2) - (lower_bound(b.begin(), b.end(), h - i + 1) - b.begin());
        if (MIN > cnt) {
            ans = 1;
            MIN = cnt;
        } else if (MIN == cnt) {
            ans++;
        }
    }
    cout << MIN << ' ' << ans << '\n';
}