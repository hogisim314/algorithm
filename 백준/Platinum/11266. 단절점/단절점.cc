#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int V, E;
int u, v;
vector<int> nodes[10100];
bool res[10100];
int discover[10100];
int cnt;
int sz;

int dfs(int node, bool root) {
    discover[node] = ++cnt;
    int num = discover[node];
    int child = 0;
    for (int i = 0; i < nodes[node].size(); i++) {
        int next = nodes[node][i];
        if (discover[next] == 0) {  // 방문안했음
            child++;
            int low = dfs(next, false);
            num = min(num, low);
            if (low >= discover[node] && !root) {
                res[node] = true;
            }
        } else {  // 방문함
            num = min(discover[next], num);
        }
    }
    if (root && child > 1) {
        res[node] = true;
    }
    return num;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> V >> E;
    for (int i = 1; i <= E; i++) {
        cin >> u >> v;
        nodes[u].push_back(v);
        nodes[v].push_back(u);
    }
    for (int i = 1; i <= V; i++) {
        if (discover[i] == 0) {
            dfs(i, true);
        }
    }
    for (int i = 1; i <= V; i++) {
        if (res[i]) {
            sz++;
        }
    }
    cout << sz << '\n';
    for (int i = 1; i <= V; i++) {
        if (res[i]) {
            cout << i << ' ';
        }
    }
}