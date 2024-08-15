#include <limits.h>
#include <memory.h>

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int tc;
int N, M, W;
int S, E, T;
vector<pair<pair<int, int>, int> > Edges;
bool visited[555];
int dist[555];
int start;
bool minusCycle = false;
void bellman_ford() {
    dist[start] = 0;
    visited[start] = true;
    for (int i = 1; i <= N - 1; i++) {
        for (int j = 0; j < Edges.size(); j++) {
            int from = Edges[j].first.first;
            int to = Edges[j].first.second;
            int weight = Edges[j].second;

            if (dist[from] == INT_MAX) continue;
            if (dist[to] > dist[from] + weight) {
                visited[to] = true;
                dist[to] = dist[from] + weight;
            }
        }
    }

    for (int j = 0; j < Edges.size(); j++) {
        int from = Edges[j].first.first;
        int to = Edges[j].first.second;
        int weight = Edges[j].second;

        if (dist[from] == INT_MAX) continue;
        if (dist[to] > dist[from] + weight) {
            minusCycle = true;
            dist[to] = dist[from] + weight;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> tc;
    while (tc--) {
        // 초기화
        Edges.clear();
        for (int i = 1; i <= 500; i++) {
            dist[i] = INT_MAX;
        }
        minusCycle = false;
        memset(visited, 0, sizeof(visited));

        cin >> N >> M >> W;
        for (int i = 1; i <= M; i++) {
            cin >> S >> E >> T;
            Edges.push_back(make_pair(make_pair(S, E), T));
            Edges.push_back(make_pair(make_pair(E, S), T));
        }
        for (int i = 1; i <= W; i++) {
            cin >> S >> E >> T;
            start = S;
            Edges.push_back(make_pair(make_pair(S, E), -T));
        }
        for (int st = 1; st <= N; st++) {
            if (visited[st]) continue;
            start = st;
            for (int i = 1; i <= 500; i++) {
                dist[i] = INT_MAX;
            }
            minusCycle = false;
            bellman_ford();
            if (minusCycle) {
                cout << "YES" << '\n';
                break;
            }
        }
        if (minusCycle) continue;
        cout << "NO" << '\n';
    }
}