#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
int a, b;
vector<int> nodes[32333];
int indegree[32333];
bool visited[32333];
int cur;
queue<int> q;

int find_first_zero_indegree() {
    for (int i = 1; i <= n; i++) {
        if (visited[i] == false && indegree[i] == 0) {
            return cur = i;
        }
    }
    return cur = -1;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        indegree[b]++;
        nodes[a].push_back(b);
    }
    cur = 1;
    while (true) {
        find_first_zero_indegree();
        if (cur == -1) break;
        q.push(cur);
        visited[cur] = true;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            cout << cur << ' ';

            for (int i = 0; i < nodes[cur].size(); i++) {
                int adj = nodes[cur][i];
                indegree[adj]--;
            }
        }
    }
}