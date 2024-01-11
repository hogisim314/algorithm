#include <memory.h>

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int tc;
int n, k;
int cost_time[1111];
int x, y, w;
int dp[1111];  // dp[i]는 i번 건물이 지어지는 최소시간.
int indegree[1111];

int main() {
    cin >> tc;
    while (tc--) {
        memset(cost_time, 0, sizeof(cost_time));
        memset(dp, -1, sizeof(dp));
        memset(indegree, 0, sizeof(indegree));
        vector<int> nextBuilding[1111];
        vector<int> dep[1111];
        queue<int> q;
        int top, neighbor;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> cost_time[i];
        }
        for (int i = 1; i <= k; i++) {
            cin >> x >> y;
            indegree[y]++;
            nextBuilding[x].push_back(y);  // x 짓고 나서 지어야 하는 건물.
        }
        cin >> w;

        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                dp[i] = cost_time[i];
            }
        }

        while (!q.empty()) {
            top = q.front();
            q.pop();

            for (int i = 0; i < nextBuilding[top].size(); i++) {
                neighbor = nextBuilding[top][i];
                dp[neighbor] = max(dp[top] + cost_time[neighbor], dp[neighbor]);
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        cout << dp[w] << '\n';
    }
}
