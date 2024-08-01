#include <algorithm>
#include <iostream>
using namespace std;

int get_gcd(int p, int q) {
    int temp;
    if (p < q) {
        temp = p;
        p = q;
        q = temp;
    }
    int n;
    while (q != 0) {
        n = p % q;
        p = q;
        q = n;
    }
    return p;
}
int n;
int arr[1111111];
int ltorgcd[1111111];
int rtolgcd[1111111];
int tempgcd;
int maxgcd = -1;
int k;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        if (i == 1) ltorgcd[i] = arr[i];
        ltorgcd[i] = get_gcd(ltorgcd[i - 1], arr[i]);
    }

    for (int i = n; i >= 1; i--) {
        if (i == n) rtolgcd[i] = arr[i];
        rtolgcd[i] = get_gcd(rtolgcd[i + 1], arr[i]);
    }

    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            tempgcd = rtolgcd[2];
        } else if (i == n) {
            tempgcd = ltorgcd[n - 1];
        }
        tempgcd = get_gcd(ltorgcd[i - 1], rtolgcd[i + 1]);
        if (arr[i] % tempgcd == 0) {
            continue;
        }
        maxgcd = max(maxgcd, tempgcd);
        k = arr[i];
    }
    if (maxgcd == -1) {
        cout << -1;
        return 0;
    } else {
        cout << maxgcd << ' ' << k;
    }
}