#include <memory.h>

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int R, C, M;
int r, c, s, d, z;
int sum;
int arr[111][111];
int temp[111][111];

class Shark {
   public:
    int idx;
    int r;
    int c;
    int s;
    int d;
    int z;
    bool alive;
    Shark() {}
    Shark(int idx, int r, int c, int s, int d, int z) {
        this->r = r;
        this->c = c;
        this->s = s;
        this->d = d;
        this->z = z;
        this->alive = true;
    }
};

void print_arr() {
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

Shark sharkList[10010];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> R >> C >> M;
    for (int i = 1; i <= M; ++i) {
        cin >> r >> c >> s >> d >> z;
        sharkList[i] = Shark(i, r, c, s, d, z);
        arr[r][c] = i;
    }
    for (int j = 1; j <= C; ++j) {
        // 물고기 잡기
        for (int i = 1; i <= R; ++i) {
            if (sharkList[arr[i][j]].alive == true) {
                sum += sharkList[arr[i][j]].z;
                sharkList[arr[i][j]].alive = false;
                arr[i][j] = 0;
                break;
            }
        }
        memset(arr, 0, sizeof(arr));
        memset(temp, 0, sizeof(temp));
        // 상어이동
        for (int i = 1; i <= M; ++i) {
            if (sharkList[i].alive == false) continue;
            int cr = sharkList[i].r;
            int cc = sharkList[i].c;
            int cd = sharkList[i].d;
            int s = sharkList[i].s;
            int nr, nc, nd;
            if (cd == 1) {
                nr = cr - s;
                nc = cc;
                nd = cd;
                while (true) {
                    if (1 <= nr && nr <= R) break;
                    if (nr < 1) {
                        nr = 1 - nr + 1;
                        nd = 2;
                    } else if (nr > R) {
                        nr = R - (nr - R);
                        nd = 1;
                    }
                }
            } else if (cd == 2) {
                nr = cr + s;
                nc = cc;
                nd = cd;
                while (true) {
                    if (1 <= nr && nr <= R) break;
                    if (nr < 1) {
                        nr = 1 - nr + 1;
                        nd = 2;
                    } else if (nr > R) {
                        nr = R - (nr - R);
                        nd = 1;
                    }
                }
            } else if (cd == 3) {
                nr = cr;
                nc = cc + s;
                nd = cd;
                while (true) {
                    if (1 <= nc && nc <= C) break;
                    if (nc < 1) {
                        nc = 1 - nc + 1;
                        nd = 3;
                    } else if (nc > C) {
                        nc = C - (nc - C);
                        nd = 4;
                    }
                }
            } else if (cd == 4) {
                nr = cr;
                nc = cc - s;
                nd = cd;
                while (true) {
                    if (1 <= nc && nc <= C) break;
                    if (nc < 1) {
                        nc = 1 - nc + 1;
                        nd = 3;
                    } else if (nc > C) {
                        nc = C - (nc - C);
                        nd = 4;
                    }
                }
            }
            if (arr[nr][nc] != 0) {
                int targetIdx = arr[nr][nc];
                if (sharkList[targetIdx].z > sharkList[i].z) {
                    sharkList[i].alive = false;
                } else {
                    sharkList[targetIdx].alive = false;
                    sharkList[i].r = nr;
                    sharkList[i].c = nc;
                    sharkList[i].d = nd;
                    arr[nr][nc] = i;
                }
            } else {
                sharkList[i].r = nr;
                sharkList[i].c = nc;
                sharkList[i].d = nd;
                arr[nr][nc] = i;
            }
        }
    }
    cout << sum;
}