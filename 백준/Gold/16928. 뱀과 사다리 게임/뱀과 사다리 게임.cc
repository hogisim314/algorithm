#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n, m;
int x, y;
int u, v;
int visited[111];
vector<pair<int, int> > sadari;
vector<pair<int, int> > snake;
int ans = 987654321;

int jump(int cur) {
    for (int i = 0; i < sadari.size(); ++i) {
        if (sadari[i].first == cur) {
            return sadari[i].second;
        }
    }

    for (int i = 0; i < snake.size(); ++i) {
        if (snake[i].first == cur) {
            return snake[i].second;
        }
    }

    return 0;
}

void foo(int cur, int cnt) {
    if (cur > 100) return;
    if (visited[cur] != 0 && visited[cur] <= cnt) return;
    if (cur == 100) {
        ans = min(ans, cnt);
        return;
    }
    visited[cur] = cnt;

    for (int i = 1; i <= 6; ++i) {
        int ret = jump(cur + i);
        if (ret == 0)
            foo(cur + i, cnt + 1);
        else {
            visited[cur + i] = cnt + 1;
            foo(ret, cnt + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> x >> y;
        sadari.push_back(make_pair(x, y));
    }

    for (int i = 1; i <= m; ++i) {
        cin >> u >> v;
        snake.push_back(make_pair(u, v));
    }
    foo(1, 0);
    cout << ans;
}