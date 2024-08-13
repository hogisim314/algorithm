#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int arr[10111];
int idx = 1;
int n;

void solve(int st, int ed) {
    if (st > ed) return;
    if (st == ed) {
        cout << arr[st] << '\n';
        return;
    }
    if (st >= ed) {
        cout << "error" << '\n';
        return;
    }
    int rightIdx = 0;
    for (int i = st + 1; i <= ed; i++) {
        if (arr[i] > arr[st]) {
            rightIdx = i;
            break;
        }
    }
    if (rightIdx == 0) {
        // 큰게 없는거
        solve(st + 1, ed);
        cout << arr[st] << '\n';
        return;
    }
    solve(st + 1, rightIdx - 1);
    solve(rightIdx, ed);
    cout << arr[st] << '\n';
    return;
}

int main() {
    while (cin >> n) {
        arr[idx++] = n;
    }

    // for (int i = 1; i <= 9; i++) {
    //     cin >> n;
    //     arr[i] = n;
    // }

    solve(1, idx - 1);
}