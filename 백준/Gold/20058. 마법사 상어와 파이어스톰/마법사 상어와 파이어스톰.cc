#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
using namespace std;
int N, Q, L, len, l;
int ice[66][66];
int qlist[1111];
int di[] = {1, 0, -1, 0};
int dj[] = {0, 1, 0, -1};
int sum;
bool visited[66][66];
int maxland;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> Q;
    L = (int)pow(2, N);
    for (int i = 1; i <= L; ++i) {
        for (int j = 1; j <= L; ++j) {
            cin >> ice[i][j];
        }
    }
    for (int i = 1; i <= Q; ++i) {
        cin >> qlist[i];
    }

    for (int q = 1; q <= Q; ++q) {
        l = qlist[q];
        len = (int)pow(2, l);
        int temp[66][66];
        for (int i = 1; i <= L; i += len) {
            for (int j = 1; j <= L; j += len) {
                int sum = i + j + len - 1;
                for (int r = i; r < i + len; ++r) {
                    for (int c = j; c < j + len; ++c) {
                        temp[r][c] = ice[sum - c][r - i + j];
                    }
                }
            }
        }

        for (int i = 1; i <= L; ++i) {
            for (int j = 1; j <= L; ++j) {
                ice[i][j] = temp[i][j];
            }
        }

        int melt[66][66];
        for (int i = 1; i <= L; ++i) {
            for (int j = 1; j <= L; ++j) {
                if (ice[i][j] == 0) {
                    melt[i][j] = ice[i][j];
                    continue;
                }
                int adjicecnt = 0;
                for (int d = 0; d < 4; ++d) {
                    int ni = i + di[d];
                    int nj = j + dj[d];
                    if (ni < 1 || ni > L || nj < 1 || nj > L) continue;
                    if (ice[ni][nj] > 0) adjicecnt++;
                }
                if (adjicecnt >= 3)
                    melt[i][j] = ice[i][j];
                else {
                    melt[i][j] = ice[i][j] - 1;
                }
            }
        }

        for (int i = 1; i <= L; ++i) {
            for (int j = 1; j <= L; ++j) {
                ice[i][j] = melt[i][j];
            }
        }
    }

    for (int i = 1; i <= L; ++i) {
        for (int j = 1; j <= L; ++j) {
            sum += ice[i][j];
        }
    }

    for (int i = 1; i <= L; ++i) {
        for (int j = 1; j <= L; ++j) {
            if (visited[i][j] || ice[i][j] == 0) continue;
            int cnt = 0;
            queue<pair<int, int> > q;
            q.emplace(make_pair(i, j));
            visited[i][j] = true;
            cnt++;

            while (!q.empty()) {
                int topi = q.front().first;
                int topj = q.front().second;
                q.pop();
                for (int d = 0; d < 4; ++d) {
                    int nexti = topi + di[d];
                    int nextj = topj + dj[d];
                    if (nexti < 1 || nexti > L || nextj < 1 || nextj > L ||
                        visited[nexti][nextj] || ice[nexti][nextj] <= 0)
                        continue;
                    q.emplace(make_pair(nexti, nextj));
                    visited[nexti][nextj] = true;
                    cnt++;
                }
            }
            maxland = max(maxland, cnt);
        }
    }

    cout << sum << '\n';
    cout << maxland << '\n';
}