#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int arr[1000001];
vector<int> K;
int Index[1000001];
int ans[1000001];
int target;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int idx = 0;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        if (K.empty()) {
            K.push_back(arr[i]);
        }
        if (K[K.size() - 1] < arr[i]) {
            K.push_back(arr[i]);
            Index[i] = K.size() - 1;
        } else {
            idx = lower_bound(K.begin(), K.end(), arr[i]) - K.begin();
            K[idx] = arr[i];
            Index[i] = idx;
        }
    }
    int target = K.size() - 1;
    for (int i = n; i >= 1; i--) {
        if (Index[i] == target) {
            ans[target] = arr[i];
            target--;
            if (target == -1) break;
        }
    }
    cout << K.size() << '\n';
    for (int i = 0; i <= K.size() - 1; i++) {
        cout << ans[i] << ' ';
    }
}