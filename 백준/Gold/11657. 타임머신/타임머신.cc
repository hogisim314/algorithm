#include <limits.h>

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int N, M;
int A, B, C;
int start = 1;
vector<pair<pair<int, int>, int> > Edge;
vector<long long> dist(555, INT_MAX);

int bellman_ford() {
    for (int i = 1; i <= N - 1; i++) {
        for (int j = 0; j < Edge.size(); j++) {
            int From = Edge[j].first.first;
            int To = Edge[j].first.second;
            int cost = Edge[j].second;

            if (dist[From] == INT_MAX) continue;
            if (dist[To] > dist[From] + cost) {
                dist[To] = dist[From] + cost;
            }
        }
    }

    for (int i = 0; i < Edge.size(); i++) {
        int From = Edge[i].first.first;
        int To = Edge[i].first.second;
        int cost = Edge[i].second;

        if (dist[From] == INT_MAX) continue;
        if (dist[To] > dist[From] + cost) {
            return -1;
        }
    }
    return 0;
}

int main() {
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        cin >> A >> B >> C;
        Edge.push_back(make_pair(make_pair(A, B), C));
    }
    dist[start] = 0;
    int res = bellman_ford();

    if (res == -1) {
        cout << -1;
        return 0;
    }
    for (int i = 2; i <= N; i++) {
        if (dist[i] == INT_MAX) {
            cout << -1 << '\n';
        } else
            cout << dist[i] << '\n';
    }
}