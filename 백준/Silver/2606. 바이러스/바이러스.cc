#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
int n, p;
vector<int> com[111];
bool visited[111];

void bfs(int num) {
    queue<int> q;
    q.push(num);
    visited[num] = 1;

    while (!q.empty()) {
        int top = q.front();
        q.pop();
        for (int i = 0; i < com[top].size(); i++) {
            if (visited[com[top][i]]) continue;
            visited[com[top][i]] = true;

            q.push(com[top][i]);
        }
    }

    return;
}

int main() {
    cin >> n >> p;
    for (int i = 0; i < p; i++) {
        int a, b;
        cin >> a >> b;
        com[a].push_back(b);
        com[b].push_back(a);
    }

    bfs(1);
    int cnt = 0;
    for (int i = 2; i <= n; i++) {
        if (visited[i]) {
            cnt++;
        }
    }
    cout << cnt;
}