#include <memory.h>
#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define NUM 7
using namespace std;

int cases = 0;
int dasom;
char seat[6][6];
bool visited[6][6];
int parr[9];
int a, b;
int ti, tj;

int di[] = {1, 0, -1, 0};
int dj[] = {0, 1, 0, -1};

bool is_ok(int i, int j) {
    if (i < 1 || j < 1 || i > 5 || j > 5 || visited[i][j]) {
        return false;
    } else {
        return true;
    }
}

bool check_adj() {
    queue<pair<int, int> > q;
    memset(visited, 0, sizeof(visited));

    bool selected[6][6];
    memset(selected, 0, sizeof(selected));

    for (int i = 0; i < 7; i++) {
        int row = parr[i] / 5 + 1;
        int col = parr[i] % 5 + 1;

        if (i == 0) {
            visited[row][col] = true;
            q.push(make_pair(row, col));
        }
        selected[row][col] = 1;
    }
    int cnt = 1;

    while (!q.empty()) {
        a = q.front().first;
        b = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            ti = a + di[i];
            tj = b + dj[i];
            if (is_ok(ti, tj) && selected[ti][tj]) {
                cnt++;
                visited[ti][tj] = true;
                q.push(make_pair(ti, tj));
            }
        }
    }
    if (cnt != 7) {
        return false;
    } else {
        return true;
    }
}

void combi(int depth, int nextIdx) {
    if (depth == 7) {
        dasom = 0;
        for (int i = 0; i < 7; i++) {
            if (seat[parr[i] / 5 + 1][parr[i] % 5 + 1] == 'S') {
                dasom++;
            }
        }

        //        if (parr[0] == 5 && parr[1] == 6 && parr[2] == 7 && parr[3] ==
        //        8 &&
        //            parr[4] == 9 && parr[5] == 11) {
        //            cout << "hello";
        //        }
        if (dasom >= 4) {
            if (check_adj()) {
                cases++;
            }
        }
        return;
    }

    for (int i = nextIdx; i < 25; i++) {
        parr[depth] = i;
        combi(depth + 1, i + 1);
    }
}

int main() {
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            scanf(" %c", &seat[i][j]);
        }
    }

    combi(0, 0);

    cout << cases;
}
