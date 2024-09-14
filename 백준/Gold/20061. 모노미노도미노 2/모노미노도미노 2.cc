#include <memory.h>

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N;
int t, row, col;  // x가 행 y가 열
int grid[15][15];
int score;
int cnt;

void print_grid() {
    // for (int i = 0; i < 10; ++i) {
    //     for (int j = 0; j < 10; ++j) {
    //         cout << grid[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    cout << "Hello" << '\n';
}

void move(int shape, int x, int y) {
    if (shape == 1) {
        // 먼저 파란쪽으로 움직이고
        int idx = 5;
        while (true) {
            if (idx == 9) {
                break;
            }
            if (grid[x][idx + 1] == 1) {
                // 그다음게 차 있다면 idx에서 break
                break;
            }
            idx++;
        }
        grid[x][idx] = 1;
        // 그다음 초록색으로 움직이자.
        idx = 5;
        while (true) {
            if (idx == 9) {
                break;
            }
            if (grid[idx + 1][y] == 1) {
                // 그다음게 차 있다면 idx에서 break
                break;
            }
            idx++;
        }
        grid[idx][y] = 1;
    } else if (shape == 2) {
        // 가로로 된거
        int idx = 4;
        while (true) {
            if (idx == 8) {
                break;
            }
            if (grid[x][idx + 2] == 1) {
                // 그다음게 차 있다면 idx에서 break
                break;
            }
            idx++;
        }
        grid[x][idx] = 1;
        grid[x][idx + 1] = 1;
        // 그다음 초록색으로 움직이자.
        idx = 4;
        while (true) {
            if (idx == 9) {
                break;
            }
            if (grid[idx + 1][y] == 1 || grid[idx + 1][y + 1] == 1) {
                break;
            }
            idx++;
        }
        grid[idx][y] = 1;
        grid[idx][y + 1] = 1;
    } else if (shape == 3) {
        // 세로로 된거
        int idx = 4;
        while (true) {
            if (idx == 9) {
                break;
            }
            if (grid[x][idx + 1] == 1 || grid[x + 1][idx + 1] == 1) {
                break;
            }
            idx++;
        }
        grid[x][idx] = 1;
        grid[x + 1][idx] = 1;

        idx = 4;
        while (true) {
            if (idx == 8) {
                break;
            }
            if (grid[idx + 2][y] == 1) {
                break;
            }
            idx++;
        }
        grid[idx][y] = 1;
        grid[idx + 1][y] = 1;
    }
}

void bomb_move() {
    // 여기서 점수도 올려야함
    // 먼저 파란색부터
    int bombcnt = 0;
    int lastIdx = 0;
    for (int j = 6; j < 10; ++j) {
        if (grid[0][j] && grid[1][j] && grid[2][j] && grid[3][j]) {
            bombcnt++;
            lastIdx = j;
        }
    }
    if (lastIdx != 0) {
        for (int j = lastIdx; j >= 6; j--) {
            grid[0][j] = grid[0][j - bombcnt];
            grid[1][j] = grid[1][j - bombcnt];
            grid[2][j] = grid[2][j - bombcnt];
            grid[3][j] = grid[3][j - bombcnt];
        }
        grid[0][4] = grid[0][5] = 0;
        grid[1][4] = grid[1][5] = 0;
        grid[2][4] = grid[2][5] = 0;
        grid[3][4] = grid[3][5] = 0;
    }
    score += bombcnt;
    // 터트리고 bombcnt만큼 이동
    bombcnt = 0;
    lastIdx = 0;
    for (int i = 6; i < 10; ++i) {
        if (grid[i][0] && grid[i][1] && grid[i][2] && grid[i][3]) {
            bombcnt++;
            lastIdx = i;
        }
    }
    if (lastIdx != 0) {
        for (int i = lastIdx; i >= 6; i--) {
            grid[i][0] = grid[i - bombcnt][0];
            grid[i][1] = grid[i - bombcnt][1];
            grid[i][2] = grid[i - bombcnt][2];
            grid[i][3] = grid[i - bombcnt][3];
        }
        grid[4][0] = grid[5][0] = 0;
        grid[4][1] = grid[5][1] = 0;
        grid[4][2] = grid[5][2] = 0;
        grid[4][3] = grid[5][3] = 0;
    }
    score += bombcnt;
}

void move_soft() {
    int movecnt = 0;
    for (int j = 4; j < 6; ++j) {
        if (grid[0][j] || grid[1][j] || grid[2][j] || grid[3][j]) {
            movecnt++;
        }
    }

    for (int j = 9; j >= 4; j--) {
        grid[0][j] = grid[0][j - movecnt];
        grid[1][j] = grid[1][j - movecnt];
        grid[2][j] = grid[2][j - movecnt];
        grid[3][j] = grid[3][j - movecnt];
    }

    movecnt = 0;
    for (int i = 4; i < 6; ++i) {
        if (grid[i][0] || grid[i][1] || grid[i][2] || grid[i][3]) {
            movecnt++;
        }
    }
    for (int i = 9; i >= 4; i--) {
        grid[i][0] = grid[i - movecnt][0];
        grid[i][1] = grid[i - movecnt][1];
        grid[i][2] = grid[i - movecnt][2];
        grid[i][3] = grid[i - movecnt][3];
    }
}

void count_block() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 6; j < 10; ++j) {
            if (grid[i][j] == 1) cnt++;
        }
    }

    for (int i = 6; i < 10; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (grid[i][j] == 1) cnt++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int n = 1; n <= N; ++n) {
        cin >> t >> row >> col;
        move(t, row, col);
        // print_grid();
        bomb_move();
        move_soft();
    }
    // print_grid();
    cout << score << '\n';
    count_block();
    cout << cnt << '\n';
}