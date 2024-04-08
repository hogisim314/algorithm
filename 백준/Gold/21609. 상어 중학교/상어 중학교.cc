#include <memory.h>

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int di[] = {1, 0, -1, 0};
int dj[] = {0, 1, 0, -1};
int arr[22][22];
bool visited[22][22];
bool selected_blocks[22][22];  // 뽑힌 기준 블록 그룹
vector<vector<int> >
    candidate;  // 영토 크기 /무지개 블록 수/ 기준 블록 i / 기준 블록 j
int n, m;
int score;

void print_arr() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void print_visited() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << visited[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

bool is_ok(int i, int j, int color) {
    if (i < 1 || i > n || j < 1 || j > n || visited[i][j] || arr[i][j] == -1 ||
        !(arr[i][j] == 0 || arr[i][j] == color))
        return false;
    return true;
}

bool is_ok_for_core(int i, int j, int color) {
    if (i < 1 || i > n || j < 1 || j > n || selected_blocks[i][j] ||
        arr[i][j] == -1 || !(arr[i][j] == 0 || arr[i][j] == color))
        return false;
    return true;
}

bool block_cmp(vector<int> v1, vector<int> v2) {
    if (v1[0] > v2[0])
        return true;
    else if (v1[0] == v2[0]) {
        if (v1[1] > v2[1]) {  // 무지개블록
            return true;
        } else if (v1[1] == v2[1]) {
            if (v1[2] > v2[2]) {
                return true;
            } else if (v1[2] == v2[2]) {
                if (v1[3] > v2[3]) {
                    return true;
                }
            }
        }
    }
    return false;
}

void bfs(int i, int j, int color) {
    int corei = i;
    int corej = j;
    int territory = 1;
    int rainbowcnt = 0;
    queue<pair<int, int> > q;
    q.push(make_pair(i, j));
    visited[i][j] = true;

    while (!q.empty()) {
        int curi = q.front().first;
        int curj = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int ti = curi + di[k];
            int tj = curj + dj[k];
            if (is_ok(ti, tj, color)) {
                q.push(make_pair(ti, tj));
                visited[ti][tj] = true;
                if (arr[ti][tj] == 0) {
                    rainbowcnt++;
                }
                // 기준 블록 정하기
                else if (arr[ti][tj] != 0) {
                    if (ti < corei) {
                        corei = ti;
                        corej = tj;
                    } else if (ti == corei) {
                        if (corej < tj) {
                            corei = ti;
                            corej = tj;
                        }
                    }
                }
                territory++;
            }
        }
    }
    if (territory < 2) {
        return;
    }
    candidate.push_back({territory, rainbowcnt, corei, corej});
}

void bfs_for_core(int i, int j, int color) {
    memset(selected_blocks, 0, sizeof(selected_blocks));
    queue<pair<int, int> > q;
    q.push(make_pair(i, j));
    selected_blocks[i][j] = true;

    while (!q.empty()) {
        int curi = q.front().first;
        int curj = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int ti = curi + di[k];
            int tj = curj + dj[k];
            if (is_ok_for_core(ti, tj, color)) {
                q.push(make_pair(ti, tj));
                selected_blocks[ti][tj] = true;
            }
        }
    }
}

void gravity() {
    for (int j = 1; j <= n; j++) {
        for (int i = n - 1; i >= 1; i--) {
            if (arr[i][j] == -1 || arr[i][j] == -2 || arr[i + 1][j] >= -1)
                continue;
            else {
                int row = i;
                while (true) {
                    if (row + 1 <= n && arr[row + 1][j] == -2) {
                        row++;
                    } else {
                        break;
                    }
                }
                arr[row][j] = arr[i][j];
                arr[i][j] = -2;
            }
        }
    }
}

void rotate() {
    int temp[22][22];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            temp[i][j] = arr[j][n + 1 - i];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            arr[i][j] = temp[i][j];
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    while (true) {
        candidate.clear();
        memset(visited, 0, sizeof(visited));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (!visited[i][j] && arr[i][j] > 0) {
                    int color = arr[i][j];
                    bfs(i, j, color);
                }
                memset(visited, 0, sizeof(visited));
            }
        }
        if (candidate.empty()) break;
        sort(candidate.begin(), candidate.end(), block_cmp);
        int land = candidate[0][0];
        int rainbowcnt = candidate[0][1];
        int corei = candidate[0][2];
        int corej = candidate[0][3];
        bfs_for_core(corei, corej, arr[corei][corej]);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (selected_blocks[i][j]) {
                    arr[i][j] = -2;
                }
            }
        }
        score += land * land;
        gravity();
        rotate();
        gravity();
    }

    cout << score;
}