#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n, m, k;
int num;
int scentNum[22][22];
int duration[22][22];
int tick;

int di[] = {0, -1, 1, 0, 0};
int dj[] = {0, 0, 0, -1, 1};

class Fish {
   public:
    int r;
    int c;
    int dir;
    int live;
    int prior[5][5];
    Fish() {}
    Fish(int row, int col, int liveness) {
        r = row;
        c = col;
        live = liveness;
    }
};

Fish fishArr[405];

void print() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << scentNum[i][j] << "(" << duration[i][j] << ")" << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void one_fish_move(int fishNum) {
    int curDir = fishArr[fishNum].dir;
    // 좌우로 이동 & 빈칸으로 이동
    for (int i = 1; i <= 4; i++) {
        int tempDir = fishArr[fishNum].prior[curDir][i];
        int nextRow = fishArr[fishNum].r + di[tempDir];
        int nextCol = fishArr[fishNum].c + dj[tempDir];
        if (nextRow < 1 || nextRow > n || nextCol < 1 || nextCol > n ||
            duration[nextRow][nextCol] > 0 ||
            duration[nextRow][nextCol] == -1) {
            continue;
        } else {
            // if (fishNum == 3) {
            //     cout << nextRow << ' ' << nextCol << '\n';
            // }
            if (duration[nextRow][nextCol] == -2) {
                fishArr[scentNum[nextRow][nextCol]].live = 0;
            }
            fishArr[fishNum].r = nextRow;
            fishArr[fishNum].c = nextCol;
            fishArr[fishNum].dir = tempDir;
            scentNum[nextRow][nextCol] = fishNum;
            duration[nextRow][nextCol] = -2;
            return;
        }
    }
    // 칸이 없는 경우 자신의 냄새 방향으로 이동
    for (int i = 1; i <= 4; i++) {
        int tempDir = fishArr[fishNum].prior[curDir][i];
        int nextRow = fishArr[fishNum].r + di[tempDir];
        int nextCol = fishArr[fishNum].c + dj[tempDir];
        if (nextRow < 1 || nextRow > n || nextCol < 1 || nextCol > n ||
            scentNum[nextRow][nextCol] != fishNum) {
            continue;
        } else {
            fishArr[fishNum].r = nextRow;
            fishArr[fishNum].c = nextCol;
            fishArr[fishNum].dir = tempDir;
            scentNum[nextRow][nextCol] = fishNum;
            duration[nextRow][nextCol] = -1;
            return;
        }
    }
}

void all_fish_move() {
    for (int i = m; i >= 1; i--) {
        if (fishArr[i].live) {
            one_fish_move(i);
        }
    }
}

bool one_alive() {
    bool only_one = true;
    if (fishArr[1].live) {
        for (int i = 2; i <= m; i++) {
            if (fishArr[i].live) {
                only_one = false;
                break;
            }
        }
    } else {
        only_one = false;
    }
    return only_one;
}

void update_scent() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (duration[i][j] > 0) {
                duration[i][j]--;
                if (duration[i][j] == 0) {
                    scentNum[i][j] = 0;
                }
            } else if (duration[i][j] < 0) {
                duration[i][j] = k;
            }
        }
    }
}

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> scentNum[i][j];
            if (scentNum[i][j]) {
                Fish fish = Fish(i, j, 1);
                fishArr[scentNum[i][j]] = fish;
                duration[i][j] = k;
            }
        }
    }

    for (int i = 1; i <= m; i++) {
        cin >> fishArr[i].dir;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= 4; j++) {
            for (int k = 1; k <= 4; k++) {
                cin >> fishArr[i].prior[j][k];
            }
        }
    }

    // for (int i = 1; i <= m; i++) {
    //     cout << fishArr[i].prior[1][1] << ' ' << fishArr[i].prior[1][2] << '
    //     '
    //          << fishArr[i].prior[1][3] << ' ' << fishArr[i].prior[1][4] <<
    //          '\n';
    // }

    // all_fish_move();
    // update_scent();
    // print();

    // all_fish_move();
    // update_scent();
    // print();

    // all_fish_move();
    // update_scent();
    // print();

    while (tick <= 1000) {
        if (one_alive()) {
            cout << tick;
            return 0;
        }
        all_fish_move();
        // print();
        update_scent();
        // print();
        tick++;
    }
    cout << -1;
    return 0;
}