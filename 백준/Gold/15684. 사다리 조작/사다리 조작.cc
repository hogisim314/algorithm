#include <algorithm>
#include <iostream>
#include <vector>
#define HUDDLE 3
using namespace std;
int n, m, h;
int a, b;
bool is_ok;
int currow, curcol;
int minn = 300;

vector<pair<int, int> > space;

// arr[a][b] 가 1이면 오른쪽으로 이동 2이면 왼쪽으로 이동
int arr[31][11];

bool check() {  // 시뮬레이션
    is_ok = true;
    for (int i = 1; i <= n; i++) {
        currow = 0;
        curcol = i;
        while (currow != h) {
            currow++;
            if (arr[currow][curcol] == 1) {
                curcol++;
            } else if (arr[currow][curcol] == 2) {
                curcol--;
            }
        }
        if (curcol != i) {
            is_ok = false;
            break;
        }
    }
    return is_ok;
}

void dfs(int index, int depth) {
    int row = space[index].first;
    int col = space[index].second;
    if (arr[row][col] != 0 || arr[row][col + 1] != 0) {
        return;
    }
    arr[row][col] = 1;
    arr[row][col + 1] = 2;
    if (check()) {
        minn = min(minn, depth);
        arr[row][col] = 0;
        arr[row][col + 1] = 0;
        return;
    }

    for (int i = index + 1; i < space.size(); i++) {
        if (depth == 3) continue;
        dfs(i, depth + 1);
    }
    arr[row][col] = 0;
    arr[row][col + 1] = 0;

    return;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> h;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        arr[a][b] = 1;
        arr[a][b + 1] = 2;
    }

    for (int i = 1; i <= n - 1; i++) {
        for (int j = 1; j <= h; j++) {
            if (arr[j][i] == 0 && arr[j][i + 1] == 0) {
                space.push_back(make_pair(j, i));
            }
        }
    }
    if (check()) {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < space.size(); i++) {
        dfs(i, 1);
    }

    if (minn == 300 && minn > HUDDLE) {
        cout << -1;
        return 0;
    }
    cout << minn;
}