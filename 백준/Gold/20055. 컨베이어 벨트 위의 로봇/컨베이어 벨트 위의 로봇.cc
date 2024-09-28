#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
int N, K;
int A[222];
int upPos, downPos;
bool belt[222];
int ans;

void debug() {
    cout << upPos << ' ' << downPos << '\n';
    for (int i = 1; i <= 2 * N; ++i) {
        cout << A[i] << ' ';
    }
    cout << '\n';
}

bool check_exit() {
    int zerocnt = 0;
    for (int i = 1; i <= 2 * N; ++i) {
        if (A[i] == 0) zerocnt++;
    }
    if (zerocnt >= K) {
        return true;
    } else
        return false;
}

void place_robot() {
    if (A[upPos] > 0) {
        belt[upPos] = true;
        A[upPos]--;
    }
}

void move_robot() {
    if (belt[downPos]) {
        belt[downPos] = false;
    }

    int index = downPos - 1;
    if (index == 0) {
        index = 2 * N;
    }

    while (true) {
        if (belt[index]) {  // 만약 있으면
            int next = index + 1;
            if (next > 2 * N) next = 1;
            if (!(belt[next] || A[next] == 0)) {
                belt[next] = true;
                if (next == downPos) {
                    belt[next] = false;
                }
                A[next]--;
                belt[index] = false;
            }
        }
        index--;
        if (index == 0) index = 2 * N;
        if (index == upPos) {
            if (belt[index]) {
                int next = index + 1;
                if (index > 2 * N) index = 2 * N;
                if (!(belt[next] || A[next] == 0)) {
                    belt[next] = true;
                    if (next == downPos) {
                        belt[next] = false;
                    }
                    A[next]--;
                    belt[index] = false;
                }
            }
            break;
        }
    }
}

void move_trailer() {
    upPos--;
    downPos--;
    if (upPos <= 0) upPos = 2 * N;
    if (downPos <= 0) downPos = 2 * N;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K;
    for (int i = 1; i <= 2 * N; ++i) {
        cin >> A[i];
    }

    upPos = 1;
    downPos = N;

    while (true) {
        ans++;
        move_trailer();
        move_robot();
        place_robot();
        if (check_exit()) {
            break;
        }
    }
    cout << ans;
}