#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int t, n, m;
int a[1111], b[1111];
long long suma[1111], sumb[1111];
vector<long long> psuma, psumb;
int pa, pb;
long long cnt;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        suma[i] = suma[i - 1] + a[i];
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        sumb[i] = sumb[i - 1] + b[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            psuma.push_back(suma[i] - suma[j]);
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < i; j++) {
            psumb.push_back(sumb[i] - sumb[j]);
        }
    }

    sort(psuma.begin(), psuma.end());
    sort(psumb.begin(), psumb.end());

    for (int i = 0; i < psuma.size(); i++) {
        long long target = t - psuma[i];
        cnt += upper_bound(psumb.begin(), psumb.end(), target) -
               lower_bound(psumb.begin(), psumb.end(), target);
    }
    cout << cnt;
}