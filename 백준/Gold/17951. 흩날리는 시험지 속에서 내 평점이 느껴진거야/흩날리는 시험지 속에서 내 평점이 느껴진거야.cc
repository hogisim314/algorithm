#include <algorithm>
#include <iostream>
using namespace std;
int n, k;
int sum = 0;
int arr[100005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        sum += arr[i];
    }

    int lo = 0;
    int hi = sum + 1;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        int group = 0;
        int groupsum = 0;
        for (int i = 1; i <= n; ++i) {
            groupsum += arr[i];
            if (groupsum >= mid) {
                group++;
                groupsum = 0;
            }
        }
        if (group < k) {
            hi = mid;
        } else if (group >= k) {
            lo = mid;
        }
    }
    cout << lo;
}