#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n, a;
long long k;
int arr[22];
long long factorial[22];
bool appear[22];
vector<int> ans1;
long long ans2;

void foo() {
    factorial[0] = 1;
    factorial[1] = 1;
    for (int i = 2; i <= 20; i++) {
        factorial[i] = factorial[i - 1] * i;
    }
}

void koo(long long rest, int idx) {
    long long facto = factorial[n - idx];
    long long num;
    if (rest % facto == 0) {
        num = rest / facto;
    } else {
        num = rest / facto + 1;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!appear[i]) {
            cnt++;
            if (cnt == num) {
                ans1.push_back(i);
                appear[i] = true;
                break;
            }
        }
    }
    rest -= (num - 1) * facto;
    if (idx == n) {
        return;
    }
    koo(rest, idx + 1);
    return;
}

void doo() {
    for (int i = 1; i <= n; i++) {
        appear[arr[i]] = true;
        int cnt = 0;
        for (int j = 1; j <= arr[i]; j++) {
            if (!appear[j]) cnt++;
        }
        ans2 += cnt * factorial[n - i];
    }
    ans2 += 1;
}

int main() {
    foo();
    cin >> n;
    cin >> a;
    if (a == 1) {
        cin >> k;
        koo(k, 1);
        for (int i = 0; i < ans1.size(); i++) {
            cout << ans1[i] << ' ';
        }
    } else {
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }
        doo();
        cout << ans2;
    }
}