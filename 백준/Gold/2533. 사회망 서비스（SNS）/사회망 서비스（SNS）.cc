#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n;
int u, v;
vector<int> nodes[1000100];
bool visited[1000100];
int dp[1000100][2];

void DFS(int cur) {
    visited[cur] = true;

    for (int i = 0; i < nodes[cur].size(); i++) {
        if (visited[nodes[cur][i]]) continue;

        DFS(nodes[cur][i]);
        dp[cur][0] += dp[nodes[cur][i]][1];
        dp[cur][1] += min(dp[nodes[cur][i]][0], dp[nodes[cur][i]][1]);
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> u >> v;
        nodes[u].push_back(v);
        nodes[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        dp[i][1] = 1;
        sort(nodes[i].begin(), nodes[i].end());
    }

    DFS(1);
    cout << min(dp[1][0], dp[1][1]);
}