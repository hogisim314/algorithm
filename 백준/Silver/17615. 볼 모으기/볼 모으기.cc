#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int n;
string s;
int ans = 987654321, cnt;
int rcnt, bcnt;
int leftR, leftB, rightR, rightB;
int main() {
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'R')
            rcnt++;
        else if (s[i] == 'B')
            bcnt++;
    }

    if (s[0] == 'R') {
        leftR++;
        int idx = 1;
        while (true) {
            if (idx > n - 1) break;
            if (s[idx] == 'R') {
                leftR++;
                idx++;
            } else
                break;
        }
    } else if (s[0] == 'B') {
        leftB++;
        int idx = 1;
        while (true) {
            if (idx > n - 1) break;
            if (s[idx] == 'B') {
                leftB++;
                idx++;
            } else
                break;
        }
    }

    if (s[n - 1] == 'R') {
        rightR++;
        int idx = n - 2;
        while (true) {
            if (idx < 0) break;
            if (s[idx] == 'R') {
                rightR++;
                idx--;
            } else
                break;
        }
    }

    else if (s[n - 1] == 'B') {
        rightB++;
        int idx = n - 2;
        while (true) {
            if (idx < 0) break;
            if (s[idx] == 'B') {
                rightB++;
                idx--;
            } else
                break;
        }
    }
    // cout << rcnt << ' ' << bcnt << '\n';
    // cout << leftR << ' ' << leftB << ' ' << rightR << ' ' << rightB << '\n';
    if (leftR > 0) {
        ans = min(ans, rcnt - leftR);
        ans = min(ans, bcnt);
    } else if (leftB > 0) {
        ans = min(ans, bcnt - leftB);
        ans = min(ans, rcnt);
    }

    if (rightR > 0) {
        ans = min(ans, rcnt - rightR);
        ans = min(ans, bcnt);
    } else if (rightB > 0) {
        ans = min(ans, bcnt - rightB);
        ans = min(ans, rcnt);
    }
    cout << ans;
}