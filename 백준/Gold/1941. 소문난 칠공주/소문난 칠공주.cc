#include <memory.h>
#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

char seat[6][6];
int parr[8];
bool visited[6][6];
bool chosen_seat[6][6];

int di[] = {1, 0, -1, 0};
int dj[] = {0, 1, 0, -1};

int minn = 30;
int cases;

bool is_ok(int i, int j) {
    if (i < 0 || i > 5 || j < 0 || j > 5 || chosen_seat[i][j] == false ||
        visited[i][j] == true) {
        return false;
    }
    return true;
}

bool check_adj() {
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int> > q;

    q.push(make_pair(parr[0] / 5, parr[0] % 5));
    int cnt = 1;
    visited[parr[0] / 5][parr[0] % 5] = true;
    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++) {
            int new_row = row + di[i];
            int new_col = col + dj[i];

            if (is_ok(new_row, new_col)) {
                cnt++;
                visited[new_row][new_col] = true;
                q.push(make_pair(new_row, new_col));
            }
        }
    }

    if (cnt != 7) return false;
    return true;
}
void combi(int depth, int nextIdx) {
    if (depth == 7) {
        int S_cnt = 0;
        memset(chosen_seat, 0, sizeof(chosen_seat));
        for (int i = 0; i < 7; i++) {
            chosen_seat[parr[i] / 5][parr[i] % 5] = true;
            if (seat[parr[i] / 5][parr[i] % 5] == 'S') {
                S_cnt++;
            }
        }
        if (check_adj()) {
            if (S_cnt >= 4) {
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
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            scanf(" %c", &seat[i][j]);
        }
    }
    combi(0, 0);
    cout << cases;
}
