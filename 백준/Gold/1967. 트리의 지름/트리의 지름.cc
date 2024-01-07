#include <memory.h>

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n;
int v1, v2, w, top;
vector<pair<int, int> > node[10005];
bool visited[10005];
int dist[10005];
int maxx = 0;
int get_max(int a, int b) { return a > b ? a : b; }

void bfs(int st) {
    queue<int> q;
    memset(visited, 0, sizeof(visited));
    memset(dist, 0, sizeof(dist));
    dist[st] = 0;
    q.push(st);
    visited[st] = true;

    while (!q.empty()) {
        top = q.front();
        q.pop();
        for (int i = 0; i < node[top].size(); i++) {
            if (!visited[node[top][i].first]) {
                visited[node[top][i].first] = true;
                dist[node[top][i].first] = dist[top] + node[top][i].second;
                maxx = maxx > dist[node[top][i].first]
                           ? maxx
                           : dist[node[top][i].first];
                q.push(node[top][i].first);
            }
        }
    }
}

int main() {
    cin >> n;
    while (cin >> v1 >> v2 >> w) {
        node[v1].push_back(make_pair(v2, w));
        node[v2].push_back(make_pair(v1, w));
    }

    for (int i = 1; i <= n; i++) {
        bfs(i);
    }
    cout << maxx;
}