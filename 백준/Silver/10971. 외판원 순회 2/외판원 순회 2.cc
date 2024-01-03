#include <memory.h>

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n;
int cost[11][11];
bool visited[11];
int sum = 0, minn = 987654321;
int root;

void backtrack(int node, int depth) {
    if (depth == 1) {
        root = node;
    }
    visited[node] = true;
    if (depth == n && cost[node][root] != 0) {
        sum += cost[node][root];
        minn = min(minn, sum);
        // cout << "node is " << node << " root is " << root << " and the sum is
        // "
        //      << sum << '\n';
        sum -= cost[node][root];
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i] || cost[node][i] == 0) continue;
        sum += cost[node][i];
        backtrack(i, depth + 1);
        sum -= cost[node][i];
        visited[i] = false;
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> cost[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        memset(visited, 0, sizeof(visited));
        backtrack(i, 1);
    }
    cout << minn;
}