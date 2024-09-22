#include <algorithm>
#include <iostream>
#include <set>
#include <string>
using namespace std;
int n;
pair<string, int> m[20005];
string arr[20005];
int ans, ansIdx, ansIdx1;

set<string> s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        if (s.find(arr[i]) != s.end()) continue;
        s.insert(arr[i]);
    }

    for (int i = 1; i <= n - 1; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            int plen = 0;
            int len = min(arr[i].size(), arr[j].size());
            for (int k = 0; k < len; ++k) {
                if (arr[i][k] != arr[j][k]) break;
                plen++;
            }
            if (plen > ans) {
                ans = plen;
                ansIdx = i;
                ansIdx1 = j;
            }
        }
    }

    cout << arr[ansIdx] << '\n' << arr[ansIdx1] << '\n';
}