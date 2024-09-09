#include <memory.h>

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int tc;
int N;
int v[10];
bool rumor[10];
double tick[10][10];
int MIN, MAX;
int cnt;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        MIN = 10;
        MAX = 0;
        cin >> N;
        memset(v, 0, sizeof(v));
        for (int i = 1; i <= N; i++) {
            cin >> v[i];
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (i == j) {
                    tick[i][j] = 0;
                    continue;
                } else {
                    tick[i][j] =
                        v[j] == v[i] ? 0 : (double)(i - j) / (v[j] - v[i]);
                    continue;
                }
            }
        }

        // cout << "time" << '\n';
        // for (int i = 1; i <= N; i++) {
        //     for (int j = 1; j <= N; j++) {
        //         cout << tick[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }

        for (int i = 1; i <= N; i++) {
            memset(rumor, false, sizeof(rumor));
            queue<pair<int, double>> q;
            q.emplace(i, 0);
            rumor[i] = true;
            cnt = 0;

            while (!q.empty()) {
                int top = q.front().first;
                double t = q.front().second;
                q.pop();
                for (int j = 1; j <= N; j++) {
                    if (!rumor[j] && tick[top][j] > 0 && tick[top][j] > t) {
                        q.emplace(j, t + tick[top][j]);
                        rumor[j] = true;
                    }
                }
            }

            for (int j = 1; j <= N; j++) {
                if (rumor[j] == true) {
                    cnt++;
                }
            }
            // cout << "i " << i << " cnt " << cnt << '\n';

            MIN = min(MIN, cnt);
            MAX = max(MAX, cnt);
        }
        cout << MIN << ' ' << MAX << '\n';
    }
}