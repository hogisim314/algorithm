#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;
int N;
int stdNum;
int likeNum;
set<int> likeStdNum[404];
int seat[22][22];
int di[] = {1, 0, -1, 0};
int dj[] = {0, 1, 0, -1};
int sum;

bool is_ok(int i, int j) {
    if (i < 1 || i > N || j < 1 || j > N) return false;
    return true;
}

pair<int, int> pick(int stdNum) {
    int maxlikecnt = 0;
    int maxEmptyCnt = 0;
    int reti = N + 1, retj = N + 1;
    int debug = 1;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (seat[i][j] != 0) continue;  // 누가 앉아있는것.
            int likecnt = 0;
            int emptycnt = 0;
            for (int d = 0; d < 4; ++d) {
                int ni = i + di[d];
                int nj = j + dj[d];
                if (ni < 1 || ni > N || nj < 1 || nj > N) continue;
                if (seat[ni][nj] == 0) {
                    emptycnt++;
                } else if (likeStdNum[stdNum].find(seat[ni][nj]) !=
                           likeStdNum[stdNum].end()) {
                    // 좋아하는 애가 인접해있음.
                    likecnt++;
                }
            }
            if (maxlikecnt < likecnt) {
                maxlikecnt = likecnt;
                maxEmptyCnt = emptycnt;
                reti = i;
                retj = j;
                debug = 1;
            } else if (maxlikecnt == likecnt) {
                if (maxEmptyCnt < emptycnt) {
                    maxEmptyCnt = emptycnt;
                    reti = i;
                    retj = j;
                    debug = 2;
                } else if (maxEmptyCnt == emptycnt) {
                    if (reti > i) {
                        maxlikecnt = likecnt;
                        maxEmptyCnt = emptycnt;
                        reti = i;
                        retj = j;
                        debug = 3;
                    } else if (reti == i) {
                        if (retj > j) {
                            maxlikecnt = likecnt;
                            maxEmptyCnt = emptycnt;
                            reti = i;
                            retj = j;
                            debug = 4;
                        }
                    }
                }
            }
        }
    }
    return make_pair(reti, retj);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N * N; ++i) {
        cin >> stdNum;
        for (int j = 0; j < 4; ++j) {
            cin >> likeNum;
            likeStdNum[stdNum].insert(likeNum);
        }
        pair<int, int> ret = pick(stdNum);
        seat[ret.first][ret.second] = stdNum;
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            stdNum = seat[i][j];
            int likecnt = 0;
            for (int d = 0; d < 4; ++d) {
                int ni = i + di[d];
                int nj = j + dj[d];
                if (ni < 1 || ni > N || nj < 1 || nj > N) continue;
                if (likeStdNum[stdNum].find(seat[ni][nj]) !=
                    likeStdNum[stdNum].end()) {
                    likecnt++;
                }
            }
            if (likecnt == 0) {
                sum += 0;
            } else if (likecnt == 1) {
                sum += 1;
            } else if (likecnt == 2) {
                sum += 10;
            } else if (likecnt == 3) {
                sum += 100;
            } else if (likecnt == 4) {
                sum += 1000;
            }
        }
    }

    // for (int i = 1; i <= N; ++i) {
    //     for (int j = 1; j <= N; ++j) {
    //         cout << seat[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    cout << sum << '\n';
}