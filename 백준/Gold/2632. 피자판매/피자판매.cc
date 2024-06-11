#include <algorithm>
#include <deque>
#include <iostream>
using namespace std;
int sz, m, n;
int pizzaA[1001], pizzaB[1001];
int sumAllA, sumAllB;
int sumA[1000100], sumB[1000100];
int prefixA[1000100], prefixB[1000100];
int idxA, idxB;
int cnt;
int main() {
    cin >> sz >> m >> n;
    for (int i = 0; i < m; i++) {
        cin >> pizzaA[i];
        sumAllA += pizzaA[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> pizzaB[i];
        sumAllB += pizzaB[i];
    }

    prefixA[0] = pizzaA[0];
    for (int i = 1; i < m; i++) {
        prefixA[i] = prefixA[i - 1] + pizzaA[i];
    }

    prefixB[0] = pizzaB[0];
    for (int i = 1; i < n; i++) {
        prefixB[i] = prefixB[i - 1] + pizzaB[i];
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (i == j) {
                sumA[idxA++] = pizzaA[i];
                continue;
            }
            if (i == 0) {
                sumA[idxA++] = prefixA[j];
                continue;
            }
            if (i > j) {
                // cout << i << ' ' << j << ' ' << sumAllA << ' ' << prefixA[i -
                // 1]
                //      << ' ' << prefixA[j] << '\n';
                if (prefixA[i - 1] - prefixA[j] == 0) continue;
                sumA[idxA++] = sumAllA - (prefixA[i - 1] - prefixA[j]);
                continue;
            }
            if (prefixA[j] - prefixA[i - 1] == sumAllA) continue;
            sumA[idxA++] = prefixA[j] - prefixA[i - 1];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                sumB[idxB++] = pizzaB[i];
                continue;
            }
            if (i == 0) {
                sumB[idxB++] = prefixB[j];
                continue;
            }
            if (i > j) {
                if (prefixB[i - 1] - prefixB[j] == 0) continue;
                sumB[idxB++] = sumAllB - (prefixB[i - 1] - prefixB[j]);
                continue;
            }
            if (prefixB[j] - prefixB[i - 1] == sumAllB) continue;
            sumB[idxB++] = prefixB[j] - prefixB[i - 1];
        }
    }

    sort(sumA, sumA + idxA);
    sort(sumB, sumB + idxB);

    // for (int i = 0; i < idxA; i++) {
    //     cout << sumA[i] << ' ';
    // }
    // cout << '\n';

    for (int i = 0; i < idxA; i++) {
        if (sumA[i] == sz) {
            cnt++;
        } else if (sumA[i] < sz) {
            cnt += (upper_bound(sumB, sumB + idxB, sz - sumA[i]) -
                    lower_bound(sumB, sumB + idxB, sz - sumA[i]));
        }
    }

    for (int i = 0; i < idxB; i++) {
        if (sumB[i] == sz) {
            cnt++;
        }
    }

    cout << cnt;
}