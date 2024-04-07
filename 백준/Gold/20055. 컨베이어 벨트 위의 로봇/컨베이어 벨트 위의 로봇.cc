#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n, k;
int naegoodo[222];
bool belt[222];
int upPos, downPos;
int step = 1;

void print() {
    for (int i = 1; i <= 2 * n; i++) {
        cout << naegoodo[i] << ' ';
    }
    cout << '\n';
}

void print1() {
    for (int i = 1; i <= 2 * n; i++) {
        cout << belt[i] << ' ';
    }
    cout << '\n';
}

bool is_finished() {
    int cnt = 0;
    for (int i = 1; i <= 2 * n; i++) {
        if (naegoodo[i] == 0) {
            cnt++;
        }
    }
    if (cnt >= k) {
        return true;
    }
    return false;
}

void move_all() {
    // 올리는 위치와 내리는 위치 옮겨줌.
    upPos--;
    if (upPos == 0) {
        upPos = 2 * n;
    }

    downPos--;
    if (downPos == 0) {
        downPos = 2 * n;
    }

    if (belt[downPos]) {
        belt[downPos] = false;
    }

    int index = downPos - 1;
    if (index == 0) {
        index = 2 * n;
    }
    while (true) {
        // cout << upPos << ' ' << downPos << ' ' << index << '\n';
        if (belt[index]) {
            int next = index + 1;
            if (next > 2 * n) {
                next = 1;
            }
            if (belt[next] == false && naegoodo[next] >= 1) {
                naegoodo[next]--;
                belt[next] = true;
                if (next == downPos) {
                    belt[next] = false;
                }
                belt[index] = false;
            }
        }

        index--;
        if (index == 0) {
            index = 2 * n;
        }
        if (index == upPos) {
            if (belt[index]) {
                int next = index + 1;
                if (next > 2 * n) {
                    next = 1;
                }
                if (belt[next] == false && naegoodo[next] >= 1) {
                    naegoodo[next]--;
                    belt[next] = true;
                    if (next == downPos) {
                        belt[next] = false;
                    }
                    belt[index] = false;
                }
            }
            break;
        }
    }
}

void lift() {
    if (naegoodo[upPos] != 0) {
        naegoodo[upPos]--;
        belt[upPos] = true;
    }
}

int main() {
    cin >> n >> k;
    upPos = 1;
    downPos = n;
    for (int i = 1; i <= 2 * n; i++) {
        cin >> naegoodo[i];
    }

    while (true) {
        move_all();
        lift();
        if (is_finished()) {
            break;
        }
        step++;
    }
    cout << step;
}