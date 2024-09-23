#include <memory.h>

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int r, c, k;
int arr[105][105];
int cnt[105];
int newRow = 3, newCol = 3;
int row = 3, col = 3;
int tick;

bool custom_cmp(pair<int, int> p1, pair<int, int> p2) {
    if (p1.second < p2.second) {
        return true;
    } else if (p1.second == p2.second) {
        if (p1.first < p2.first) {
            return true;
        }
    }
    return false;
}

void print_arr() {
    for (int i = 1; i <= row; ++i) {
        for (int j = 1; j <= col; ++j) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> r >> c >> k;
    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 3; ++j) {
            cin >> arr[i][j];
        }
    }
    while (true) {
        if (arr[r][c] == k) {
            break;
        }
        if (tick > 100) break;
        if (row >= col) {
            // 행에 대해 정렬
            newCol = col;
            for (int i = 1; i <= row; ++i) {
                memset(cnt, 0, sizeof(cnt));
                vector<pair<int, int> > v;
                for (int j = 1; j <= col; ++j) {
                    if (arr[i][j] == 0) continue;
                    cnt[arr[i][j]]++;
                }
                for (int k = 1; k <= 100; ++k) {
                    if (cnt[k] == 0) continue;
                    v.emplace_back(make_pair(k, cnt[k]));
                }
                sort(v.begin(), v.end(), custom_cmp);
                for (int j = 1; j <= 100; ++j) {
                    arr[i][j] = 0;
                }
                int idx = 1;
                for (int j = 0; j < v.size(); ++j) {
                    arr[i][idx] = v[j].first;
                    idx++;
                    if (idx > 100) break;
                    arr[i][idx] = v[j].second;
                    idx++;
                    if (idx > 100) break;
                }
                newCol = max(newCol, idx - 1);
            }
            col = newCol;
            tick++;
            // print_arr();
        } else {
            // 열에 대해 정렬
            newRow = row;
            for (int j = 1; j <= col; ++j) {
                memset(cnt, 0, sizeof(cnt));
                vector<pair<int, int> > v;
                for (int i = 1; i <= row; ++i) {
                    if (arr[i][j] == 0) continue;
                    cnt[arr[i][j]]++;
                }
                for (int k = 1; k <= 100; ++k) {
                    if (cnt[k] == 0) continue;
                    v.emplace_back(make_pair(k, cnt[k]));
                }
                sort(v.begin(), v.end(), custom_cmp);
                for (int i = 1; i <= 100; ++i) {
                    arr[i][j] = 0;
                }
                int idx = 1;
                for (int i = 0; i < v.size(); ++i) {
                    arr[idx][j] = v[i].first;
                    idx++;
                    if (idx > 100) break;
                    arr[idx][j] = v[i].second;
                    idx++;
                    if (idx > 100) break;
                }
                newRow = max(newRow, idx - 1);
            }
            row = newRow;
            tick++;
            // print_arr();
        }
    }
    if (tick > 100) {
        cout << -1;
        return 0;
    }
    cout << tick;
}