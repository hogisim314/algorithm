#include <math.h>

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N, Q;
int A[70][70];
int q_list[1111];
int len;
int di[] = {1, 0, -1, 0};
int dj[] = {0, 1, 0, -1};
int maxx;
bool visited[70][70];

bool is_in(int i, int j) {
    if (i < 1 || i > len || j < 1 || j > len) return false;
    return true;
}

bool is_in_bfs(int i, int j) {
    if (i < 1 || i > len || j < 1 || j > len || visited[i][j] || A[i][j] == 0)
        return false;
    return true;
}

void bfs(int i, int j) {
    queue<pair<int, int> > q;
    q.push(make_pair(i, j));
    visited[i][j] = true;
    int land = 1;
    while (!q.empty()) {
        int topi = q.front().first;
        int topj = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++) {
            int ti = topi + di[k];
            int tj = topj + dj[k];

            if (is_in_bfs(ti, tj)) {
                q.push(make_pair(ti, tj));
                visited[ti][tj] = true;
                land++;
            }
        }
    }
    maxx = max(maxx, land);
}

void print() {
    for (int i = 1; i <= len; i++) {
        for (int j = 1; j <= len; j++) {
            cout << A[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void melt() {
    int temp[70][70];

    for (int i = 1; i <= len; i++) {
        for (int j = 1; j <= len; j++) {
            temp[i][j] = A[i][j];
        }
    }

    for (int i = 1; i <= len; i++) {
        for (int j = 1; j <= len; j++) {
            if (A[i][j] == 0) continue;
            // 양수여야 진행
            int cnt = 0;
            for (int k = 0; k < 4; k++) {
                int ti = i + di[k];
                int tj = j + dj[k];
                if (is_in(ti, tj)) {
                    if (A[ti][tj] > 0) {
                        cnt++;
                    }
                }
            }
            if (cnt < 3) {
                temp[i][j]--;
            }
        }
    }

    for (int i = 1; i <= len; i++) {
        for (int j = 1; j <= len; j++) {
            A[i][j] = temp[i][j];
        }
    }
}

void rotate_one(int row, int col, int l) {
    int** arr = new int*[l + 1];
    int** temp = new int*[l + 1];
    for (int i = 0; i < l + 1; i++) {
        arr[i] = new int[l + 1];
        temp[i] = new int[l + 1];
    }

    for (int i = 1; i <= l; i++) {
        for (int j = 1; j <= l; j++) {
            arr[i][j] = A[row + i - 1][col + j - 1];
        }
    }

    for (int i = 1; i <= l; i++) {
        for (int j = 1; j <= l; j++) {
            temp[i][j] = arr[l + 1 - j][i];
        }
    }

    for (int i = 1; i <= l; i++) {
        for (int j = 1; j <= l; j++) {
            A[row + i - 1][col + j - 1] = temp[i][j];
        }
    }

    for (int i = 0; i < l + 1; i++) {
        delete[] arr[i];
        delete[] temp[i];
    }

    delete[] arr;
    delete[] temp;
}

void rotate_all(int step) {
    int templen = pow(2, step);
    for (int i = 1; i <= len; i += templen) {
        for (int j = 1; j <= len; j += templen) {
            rotate_one(i, j, templen);
        }
    }
}

void solution() {
    for (int i = 1; i <= Q; i++) {
        rotate_all(q_list[i]);
        melt();
    }
    int sum = 0;
    for (int i = 1; i <= len; i++) {
        for (int j = 1; j <= len; j++) {
            sum += A[i][j];
        }
    }
    cout << sum << '\n';
    for (int i = 1; i <= len; i++) {
        for (int j = 1; j <= len; j++) {
            if (!visited[i][j] && A[i][j] > 0) {
                bfs(i, j);
            }
        }
    }
    cout << maxx << '\n';
}

int main() {
    cin >> N >> Q;
    len = pow(2, N);
    for (int i = 1; i <= len; i++) {
        for (int j = 1; j <= len; j++) {
            cin >> A[i][j];
        }
    }

    for (int i = 1; i <= Q; i++) {
        cin >> q_list[i];
    }

    solution();
}