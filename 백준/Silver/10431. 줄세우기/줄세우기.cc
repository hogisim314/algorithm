#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
int P;
int sum;
int kids[22];
int h;
int idx;
int main() {
    cin >> P;
    for (int p = 1; p <= P; p++) {
        sum = 0;

        for (int i = 1; i <= 20; i++) {
            kids[i] = 0;
        }

        cin >> idx;
        cin >> h;
        kids[1] = h;

        for (int i = 2; i <= 20; i++) {
            cin >> h;
            bool change = false;
            for (int j = 1; j <= i - 1; j++) {
                if (kids[j] > h) {
                    for (int k = i - 1; k >= j; k--) {
                        kids[k + 1] = kids[k];
                    }
                    sum += (i - j);
                    change = true;
                    kids[j] = h;
                    break;
                } else
                    continue;
            }
            if (!change) kids[i] = h;
            // cout << "debug" << ' ';
            // for (int j = 1; j <= 20; j++) {
            //     cout << kids[j] << ' ';
            // }
            // cout << '\n';
        }
        cout << p << ' ' << sum << '\n';
    }
}