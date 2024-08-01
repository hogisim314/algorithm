#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n;
int arr[1000100];
int lo, hi;
int cnt;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    int x;
    cin >> x;
    lo = 1;
    hi = n;
    sort(arr + 1, arr + n + 1);
    while (lo < hi) {
        if (arr[lo] + arr[hi] == x) {
            cnt++;
            hi--;
        } else if (arr[lo] + arr[hi] > x) {
            hi--;
        } else if (arr[lo] + arr[hi] < x) {
            lo++;
        }
    }
    cout << cnt;
}