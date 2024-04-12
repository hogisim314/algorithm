#include <math.h>

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N, K;
int fishBowlList[110];
int stack[110][110];
int maxHeight;
int di[] = {0, 1, 0, -1, 0};
int dj[] = {0, 0, 1, 0, -1};
int initialPos, initialPos2;  // 그냥 pos는 높이 2이상 블록이 끝나는 위치.
                              // pos2는 높이 2이상 블럭시작 직전 위치

int get_diff() {
    int maxx = -1;
    int minn = 210000000;
    for (int i = 1; i <= N; i++) {
        maxx = max(maxx, fishBowlList[i]);
        minn = min(minn, fishBowlList[i]);
    }
    return maxx - minn;
}

void print_fishBowlList() {
    for (int i = 1; i <= N; i++) {
        cout << fishBowlList[i] << ' ';
    }
    cout << '\n';
}

void print_stacking(int i1, int j1, int i2, int j2) {
    for (int i = i1; i <= i2; i++) {
        for (int j = j1; j <= j2; j++) {
            cout << stack[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void go_half_once() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            stack[i][j] = 0;
        }
    }

    for (int i = 1; i <= N / 2; i++) {
        stack[2][N + 1 - i] = fishBowlList[i];
    }

    for (int i = N / 2 + 1; i <= N; i++) {
        stack[1][i] = fishBowlList[i];
    }
}

void go_half_twice() {
    int col = 3 * N / 4 + 1;
    for (int j = 3 * N / 4; j >= N / 2 + 1; j--) {
        int row = 3;
        for (int i = 2; i >= 1; i--) {
            stack[row][col] = stack[i][j];
            row++;
            stack[i][j] = 0;
        }
        col++;
    }
}

void go_flat(int initialPos, int maxHeight) {
    vector<int> temp;
    for (int j = initialPos; j <= N; j++) {
        for (int i = 1; i <= maxHeight; i++) {
            if (stack[i][j]) {
                temp.push_back(stack[i][j]);
            }
        }
    }
    for (int i = 0; i < temp.size(); i++) {
        fishBowlList[i + 1] = temp[i];
    }
}

void control_fish(int initialPos, int maxHeight) {
    int stack_delta[110][110];
    int delta;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            stack_delta[i][j] = 0;
        }
    }

    for (int i = 1; i <= maxHeight; i++) {
        for (int j = initialPos; j <= N - 1; j++) {
            if (stack[i][j] && stack[i][j + 1]) {
                delta = abs((stack[i][j] - stack[i][j + 1])) / 5;
                if (delta > 0) {
                    if (stack[i][j] > stack[i][j + 1]) {
                        stack_delta[i][j] -= delta;
                        stack_delta[i][j + 1] += delta;
                    }
                    if (stack[i][j] < stack[i][j + 1]) {
                        stack_delta[i][j] += delta;
                        stack_delta[i][j + 1] -= delta;
                    }
                }
            }
        }
    }

    for (int j = initialPos; j <= N; j++) {
        for (int i = 1; i <= maxHeight - 1; i++) {
            if (stack[i][j] && stack[i + 1][j]) {
                delta = abs((stack[i][j] - stack[i + 1][j])) / 5;
                if (delta > 0) {
                    if (stack[i][j] > stack[i + 1][j]) {
                        stack_delta[i][j] -= delta;
                        stack_delta[i + 1][j] += delta;
                    }
                    if (stack[i][j] < stack[i + 1][j]) {
                        stack_delta[i][j] += delta;
                        stack_delta[i + 1][j] -= delta;
                    }
                }
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            stack[i][j] += stack_delta[i][j];
        }
    }
}

void stacking() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            stack[i][j] = 0;
        }
    }

    for (int j = 1; j <= N; j++) {
        stack[1][j] = fishBowlList[j];
    }

    // first stack
    int lineHeight = 2;
    stack[2][2] = stack[1][1];
    stack[1][1] = 0;
    bool initFound = false;
    for (int j = N; j >= 2; j--) {
        int rowIdx = 1;
        if (stack[2][j - 1] && !initFound) {
            initialPos = j;
            initFound = true;
        }
        vector<int> temp;
        while (true) {
            if (stack[rowIdx][j] <= 0) {
                break;
            }
            temp.push_back(stack[rowIdx][j]);
            // stack[rowIdx][j] = 0;
            rowIdx++;
        }
        if (temp.size() >= 2) {
            for (int k = 0; k < temp.size(); k++) {
                stack[lineHeight][initialPos + k] = temp[k];
            }
            for (int row = 1; row <= rowIdx; row++) {
                stack[row][j] = 0;
            }
        }
    }
    bool terminate = false;
    while (true) {
        lineHeight = 2;
        initFound = false;

        for (int j = N; j >= initialPos; j--) {
            int rowIdx = 1;
            if (stack[2][j - 1] && !initFound) {
                initialPos2 = j;
                initFound = true;
            }
            vector<int> temp;
            while (true) {
                if (stack[rowIdx][j] <= 0) {
                    break;
                }
                temp.push_back(stack[rowIdx][j]);
                rowIdx++;
            }
            if (temp.size() >= 2) {
                for (int k = 0; k < temp.size(); k++) {
                    maxHeight = temp.size();
                    if (initialPos2 + temp.size() > N + 1) {
                        terminate = true;
                        break;
                    }
                    stack[lineHeight][initialPos2 + k] = temp[k];
                }
                if (terminate) {
                    break;
                }
                for (int row = 1; row <= rowIdx; row++) {
                    stack[row][j] = 0;
                }
                lineHeight++;
            }
        }
        if (terminate) break;
        initialPos = initialPos2;
    }
}

void plus_one_to_min() {
    vector<int> idx;
    int minn = 210000000;
    for (int i = 1; i <= N; i++) {
        minn = min(minn, fishBowlList[i]);
    }
    for (int i = 1; i <= N; i++) {
        if (fishBowlList[i] == minn) {
            fishBowlList[i]++;
        }
    }
}

void solution() {
    int cnt = 0;
    while (true) {
        if (get_diff() <= K) {
            cout << cnt;
            return;
        }
        cnt++;
        plus_one_to_min();
        stacking();
        control_fish(initialPos, maxHeight);
        go_flat(initialPos, maxHeight);
        go_half_once();
        go_half_twice();
        control_fish(3 * N / 4 + 1, 4);
        go_flat(3 * N / 4 + 1, 4);
    }
}

void input() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> fishBowlList[i];
    }
}

int main() {
    input();
    solution();
}