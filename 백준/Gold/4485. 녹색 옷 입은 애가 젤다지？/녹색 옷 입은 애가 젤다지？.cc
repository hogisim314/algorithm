#include <limits.h>

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n;
int tc = 1;
int grid[130][130];
int ans;
int dist[130][130];
int weight, curi, curj, adji, adjj;
vector<pair<int, int> > nodes[130][130];

int di[] = {1, 0, -1, 0};
int dj[] = {0, 1, 0, -1};

bool is_ok(int i, int j) {
    if (i < 1 || i > n || j < 1 || j > n) {
        return false;
    }
    return true;
}

void init() {
    for (int i = 0; i < 130; i++) {
        for (int j = 0; j < 130; j++) {
            dist[i][j] = INT_MAX;
            grid[i][j] = 0;
        }
    }
}

void link() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k < 4; k++) {
                int ti = i + di[k];
                int tj = j + dj[k];
                if (is_ok(ti, tj)) {
                    nodes[i][j].push_back(make_pair(ti, tj));
                }
            }
        }
    }
}

void dijkstra() {
    priority_queue<pair<int, pair<int, int> > > pq;
    pq.push(make_pair(-grid[1][1], make_pair(1, 1)));

    while (!pq.empty()) {
        weight = -pq.top().first;
        curi = pq.top().second.first;
        curj = pq.top().second.second;
        pq.pop();
        if (dist[curi][curj] != INT_MAX) continue;
        dist[curi][curj] = weight;

        for (int i = 0; i < nodes[curi][curj].size(); i++) {
            adji = nodes[curi][curj][i].first;
            adjj = nodes[curi][curj][i].second;
            weight = grid[adji][adjj];

            if (dist[adji][adjj] > dist[curi][curj] + weight) {
                pq.push(make_pair(-(dist[curi][curj] + weight),
                                  make_pair(adji, adjj)));
            }
        }
    }
}

int main() {
    while (true) {
        cin >> n;
        if (n == 0) break;
        init();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> grid[i][j];
            }
        }
        link();
        dijkstra();
        cout << "Problem " << tc++ << ": " << dist[n][n] << '\n';
    }
}