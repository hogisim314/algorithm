#include <memory.h>

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int D, W, K;
int arr[20][20];
int temp[20][20];
int rows_to_change[15];

bool accept() {
    bool flag = false;
    bool is_ok[22];
    memset(is_ok, 0, sizeof(is_ok));
    for (int j = 1; j <= W; j++) {
        for (int i = 1; i <= D - K + 1; i++) {
            int temp = arr[i][j];
            for (int k = 1; k <= K - 1; k++) {
                if (arr[i + k][j] == temp) {
                    flag = true;
                    continue;
                } else {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                is_ok[j] = true;
                break;
            }
        }
    }
    for (int j = 1; j <= W; j++) {
        if (!is_ok[j]) {
            return false;
        }
    }
    return true;
}

bool dfs(int index, int pickCnt) {
    if (index == pickCnt + 1) {
        if (accept()) {
            return true;
        }
        return false;
    }

    for (int j = 1; j <= W; j++) {
        arr[rows_to_change[index]][j] = 0;
    }
    if (dfs(index + 1, pickCnt)) {
        return true;
    }
    for (int j = 1; j <= W; j++) {
        arr[rows_to_change[index]][j] = 1;
    }
    if (dfs(index + 1, pickCnt)) {
        return true;
    }
    return false;
}

bool simulation(int pickCnt) {
    bool res = false;
    for (int i = 1; i <= D; i++) {
        for (int j = 1; j <= W; j++) {
            temp[i][j] = arr[i][j];
        }
    }

    if (dfs(1, pickCnt)) {
        res = true;
    }

    // for (int r = 1; r <= pickCnt; r++) {
    //     // 한번은 0
    //     for (int j = 1; j <= W; j++) {
    //         arr[rows_to_change[r]][j] = 0;
    //     }
    // }

    // if (accept()) {
    //     res = true;
    // }

    // for (int r = 1; r <= pickCnt; r++) {
    //     // 한번은 1해야함.
    //     for (int j = 1; j <= W; j++) {
    //         arr[rows_to_change[r]][j] = 1;
    //     }
    // }

    // if (accept()) {
    //     res = true;
    // }

    for (int i = 1; i <= D; i++) {
        for (int j = 1; j <= W; j++) {
            arr[i][j] = temp[i][j];
        }
    }
    return res;
}

bool combi(int depth, int nextIdx, int pickCnt) {
    if (depth == pickCnt + 1) {
        if (simulation(pickCnt)) {
            return true;
        }
        return false;
    }

    for (int i = nextIdx; i <= D; i++) {
        rows_to_change[depth] = i;
        bool res = combi(depth + 1, i + 1, pickCnt);
        if (res) {
            return true;
        }
    }
    return false;
}

int solution() {
    // 약품투입 안해도 되는 케이스들
    if (K == 1 || accept()) {
        return 0;
    }
    // 약품투입하기 시작
    for (int m = 1; m <= D; m++) {
        memset(rows_to_change, 0, sizeof(rows_to_change));
        if (combi(1, 1, m)) {
            return m;
        }
    }
}

int main(int argc, char** argv) {
    int test_case;
    int T;

    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        memset(arr, 0, sizeof(arr));
        cin >> D >> W >> K;
        for (int i = 1; i <= D; i++) {
            for (int j = 1; j <= W; j++) {
                cin >> arr[i][j];
            }
        }
        int ans = solution();
        cout << "#" << test_case << ' ' << ans << '\n';
    }
    return 0;  // 정상종료시 반드시 0을 리턴해야합니다.
}