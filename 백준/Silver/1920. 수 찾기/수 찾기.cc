#include <algorithm>
#include <iostream>
using namespace std;
int N, M;
int arr[111111];
int num;

bool binary_search(int k) {
    int lo = 1;
    int hi = N;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (arr[mid] == k) {
            return 1;
        }
        if (arr[mid] <= k) {
            lo = mid;
        } else if (arr[mid] > k) {
            hi = mid;
        }
    }
    if (arr[lo] == k || arr[hi] == k) {
        return 1;
    } else
        return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    sort(arr + 1, arr + N + 1);
    cin >> M;
    for (int i = 1; i <= M; i++) {
        cin >> num;
        cout << binary_search(num) << '\n';
    }
}