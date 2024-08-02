#include <stdio.h>

#include <algorithm>
#include <iostream>
using namespace std;
int m, k;
int arr[55];
int sum;
double ans = 0;
int main() {
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    cin >> k;

    for (int i = 1; i <= m; i++) {
        if (arr[i] < k) {
            continue;
        }
        double temp = 1;
        for (int j = 0; j < k; j++) {
            temp *= (arr[i] - j);
            temp /= (sum - j);
        }
        ans += temp;
    }
    printf("%.15lf", ans);
}