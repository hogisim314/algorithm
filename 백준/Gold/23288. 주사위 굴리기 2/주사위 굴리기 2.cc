#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
int N, M, K;
int arr[22][22];
int di[] = {0, 0, 0, 1, -1};  // 오른쪽 왼쪽 아랫쪽 윗쪽
int dj[] = {0, 1, -1, 0, 0};

typedef struct DICE {
    int top;
    int bottom;
    int front;
    int rear;
    int right;
    int left;
} DICE;

DICE dice;
int curi, curj, curdir;
int ans;

bool is_ok(int i, int j) {
    if (i < 1 || i > N || j < 1 || j > M) return false;
    return true;
}

void print_dice() {
    cout << "curi " << curi << " curj " << curj << '\n';
    cout << "dice top " << dice.top << " dice bottom " << dice.bottom
         << " dice left " << dice.left << " dice right " << dice.right
         << " dice front" << dice.front << " dice rear " << dice.rear << '\n';
}

void print_arr() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void judge_dir() {
    if (dice.bottom > arr[curi][curj]) {
        if (curdir == 1) {
            curdir = 3;
        } else if (curdir == 3) {
            curdir = 2;
        } else if (curdir == 2) {
            curdir = 4;
        } else if (curdir == 4) {
            curdir = 1;
        }
    } else if (dice.bottom < arr[curi][curj]) {
        if (curdir == 1) {
            curdir = 4;
        } else if (curdir == 4) {
            curdir = 2;
        } else if (curdir == 2) {
            curdir = 3;
        } else if (curdir == 3) {
            curdir = 1;
        }
    } else {
        return;
    }
}

int get_score(int i, int j) {
    queue<pair<int, int> > q;
    bool visited[22][22];

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            visited[i][j] = false;
        }
    }

    q.push(make_pair(i, j));
    visited[i][j] = 1;
    int num = arr[i][j];
    int land = 1;
    while (!q.empty()) {
        int topi = q.front().first;
        int topj = q.front().second;
        q.pop();
        for (int k = 1; k <= 4; k++) {
            int ti = topi + di[k];
            int tj = topj + dj[k];

            if (is_ok(ti, tj) && !visited[ti][tj] && arr[ti][tj] == num) {
                q.push(make_pair(ti, tj));
                visited[ti][tj] = 1;
                land++;
            }
        }
    }
    return land;
}

void rotate_dice(int dir) {
    if (dir == 1) {
        // 앞뒤는 가만히 있고 나머지 전부 바뀜.
        tuple<int, int, int, int> temp;
        temp = make_tuple(dice.left, dice.right, dice.top, dice.bottom);
        auto [l, r, t, b] = temp;

        dice.top = l;
        dice.right = t;
        dice.bottom = r;
        dice.left = b;
    } else if (dir == 2) {
        // 앞뒤는 가만히 있고 나머지 전부 바뀜.
        tuple<int, int, int, int> temp;
        temp = make_tuple(dice.left, dice.right, dice.top, dice.bottom);
        auto [l, r, t, b] = temp;

        dice.top = r;
        dice.right = b;
        dice.bottom = l;
        dice.left = t;
    } else if (dir == 3) {
        // right left는 가만히.

        tuple<int, int, int, int> temp;
        temp = make_tuple(dice.front, dice.rear, dice.top, dice.bottom);
        auto [f, r, t, b] = temp;

        dice.front = t;
        dice.bottom = f;
        dice.rear = b;
        dice.top = r;
    } else if (dir == 4) {
        // right left는 가만히.

        tuple<int, int, int, int> temp;
        temp = make_tuple(dice.front, dice.rear, dice.top, dice.bottom);
        auto [f, r, t, b] = temp;

        dice.front = b;
        dice.bottom = r;
        dice.rear = t;
        dice.top = f;
    } else {
        cout << "error" << '\n';
    }
}

void move_dice() {
    if (is_ok(curi + di[curdir], curj + dj[curdir])) {
    } else {  // 방향 반대전환
        if (curdir == 1) {
            curdir = 2;
        } else if (curdir == 2) {
            curdir = 1;
        } else if (curdir == 3) {
            curdir = 4;
        } else if (curdir == 4) {
            curdir = 3;
        }
    }

    curi += di[curdir];
    curj += dj[curdir];
    rotate_dice(curdir);
}

void solution() {
    for (int i = 1; i <= K; i++) {
        move_dice();
        // print_arr();
        // print_dice();
        int land = get_score(curi, curj);
        ans += land * arr[curi][curj];
        judge_dir();
        // cout << i << ' ' << dice.bottom << ' ' << curi << ' ' << curj << ' '
        //      << curdir << '\n';
    }
    // cout << curi << ' ' << curj << ' ' << curdir << '\n';
    cout << ans;
}

void Input() {
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> arr[i][j];
        }
    }
}

void init_dice() {
    curi = 1;
    curj = 1;
    curdir = 1;
    dice.top = 1;
    dice.bottom = 6;
    dice.front = 5;
    dice.rear = 2;
    dice.left = 4;
    dice.right = 3;
}

int main() {
    init_dice();
    Input();
    solution();
}