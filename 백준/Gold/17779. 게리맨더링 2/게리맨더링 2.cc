#include <memory.h>

#include <algorithm>
#include <iostream>
using namespace std;
int N;
int region[22][22];
int A[22][22];
int ans = 987654321;

void debug_region() {
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cout << region[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> A[i][j];
        }
    }

    for (int x = 1; x <= N; ++x) {
        for (int y = 1; y <= N; ++y) {
            for (int d1 = 1; d1 <= N; d1++) {
                for (int d2 = 1; d2 <= N; d2++) {
                    if (x + d1 + d2 <= N && 1 <= y - d1 && y + d2 <= N) {
                        // 이제 경계선 잡기
                        memset(region, 0, sizeof(region));
                        int sum[6];
                        memset(sum, 0, sizeof(sum));
                        for (int k = 0; k <= d1; ++k) {
                            region[x + k][y - k] = 5;
                            region[x + d2 + k][y + d2 - k] = 5;
                        }
                        for (int k = 0; k <= d2; ++k) {
                            region[x + k][y + k] = 5;
                            region[x + d1 + k][y - d1 + k] = 5;
                        }
                        for (int i = 1; i <= N; ++i) {
                            int st = 0, ed = 0;
                            for (int j = 1; j <= N; ++j) {
                                if (region[i][j] == 5) {
                                    if (st != 0) {
                                        ed = j;
                                    } else
                                        st = j;
                                }
                            }
                            for (int j = st; j <= ed; ++j) {
                                region[i][j] = 5;
                            }
                        }

                        // 1번 선거구
                        for (int r = 1; r < x + d1; ++r) {
                            for (int c = 1; c <= y; ++c) {
                                if (region[r][c] == 5) continue;
                                region[r][c] = 1;
                            }
                        }
                        // 2번 선거구
                        for (int r = 1; r <= x + d2; ++r) {
                            for (int c = y + 1; c <= N; ++c) {
                                if (region[r][c] == 5) continue;
                                region[r][c] = 2;
                            }
                        }
                        // 3번 선거구
                        for (int r = x + d1; r <= N; ++r) {
                            for (int c = 1; c < y - d1 + d2; ++c) {
                                if (region[r][c] == 5) continue;
                                region[r][c] = 3;
                            }
                        }
                        // 2번 선거구
                        for (int r = x + d2 + 1; r <= N; ++r) {
                            for (int c = y - d1 + d2; c <= N; ++c) {
                                if (region[r][c] == 5) continue;
                                region[r][c] = 4;
                            }
                        }

                        for (int i = 1; i <= N; ++i) {
                            for (int j = 1; j <= N; ++j) {
                                sum[region[i][j]] += A[i][j];
                            }
                        }

                        int MAX = 0, MIN = 987654321;
                        for (int i = 1; i <= 5; ++i) {
                            MAX = max(MAX, sum[i]);
                            MIN = min(MIN, sum[i]);
                        }
                        ans = min(ans, MAX - MIN);
                    }
                }
            }
        }
    }
    cout << ans;
}