#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n;
long long a[4444];
long long b[4444];
long long c[4444];
long long d[4444];

vector<long long> v1, v2;
long long cnt;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            v1.push_back(a[i] + b[j]);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            v2.push_back(c[i] + d[j]);
        }
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    for (int i = 0; i < v1.size(); i++) {
        cnt += upper_bound(v2.begin(), v2.end(), -v1[i]) -
               lower_bound(v2.begin(), v2.end(), -v1[i]);
    }
    cout << cnt;
}