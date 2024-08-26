#include <memory.h>

#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
int tc;
int n, k;
int x, y, w;
int timecost[1111];
int dptime[1111];
vector<int> nodes[1111];
int indegree[1111];
int mintime;

void topological_sort() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
            dptime[i] = timecost[i];
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < nodes[cur].size(); i++) {
            int adj = nodes[cur][i];
            indegree[adj]--;
            if (indegree[adj] == 0) {
                q.push(adj);
            }
            dptime[adj] = max(dptime[adj], dptime[cur] + timecost[adj]);
        }
    }
}

int main() {
    cin >> tc;
    while (tc--) {
        memset(timecost, 0, sizeof(timecost));
        memset(dptime, 0, sizeof(dptime));
        memset(indegree, 0, sizeof(indegree));
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> timecost[i];
        }
        for (int i = 1; i <= k; i++) {
            cin >> x >> y;
            nodes[x].push_back(y);
            indegree[y]++;
        }
        cin >> w;
        topological_sort();

        // cout << "debug" << '\n';
        // for (int i = 1; i <= n; i++) {
        //     cout << dptime[i] << ' ';
        // }
        // cout << '\n';

        cout << dptime[w] << '\n';
        for (int i = 1; i <= n; i++) {
            nodes[i].clear();
        }
    }
}