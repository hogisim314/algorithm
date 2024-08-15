#include <limits.h>
#include <memory.h>

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int W, H, G, E;
int X, Y;
int X1, Y1, X2, Y2, T;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
vector<pair<pair<pair<int, int>, pair<int, int>>, int>> Edges;
int grid[35][35];
bool grave[35][35];
bool hole[35][35];
int tempx, tempy;
int dist[35][35];
bool minusCycle = false;

bool is_ok(int x, int y) {
    if (x < 0 || x > (W - 1) || y < 0 || y > (H - 1) || grave[x][y]) {
        return false;
    }
    return true;
}

void debug() {
    cout << "Edges" << '\n';
    for (int i = 0; i < Edges.size(); i++) {
        cout << Edges[i].first.first.first << ' ' << Edges[i].first.first.second
             << ' ' << Edges[i].first.second.first << ' '
             << Edges[i].first.second.second << ' ' << Edges[i].second << '\n';
    }
    cout << "dist" << '\n';
    for (int j = H - 1; j >= 0; j--) {
        for (int i = 0; i < W; i++) {
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
}

void bellmanford() {
    for (int i = 1; i <= W * H; i++) {
        for (int j = 0; j < Edges.size(); j++) {
            int fromx = Edges[j].first.first.first;
            int fromy = Edges[j].first.first.second;
            int tox = Edges[j].first.second.first;
            int toy = Edges[j].first.second.second;
            int weight = Edges[j].second;
            if (dist[fromx][fromy] == INT_MAX) continue;
            if (dist[tox][toy] > dist[fromx][fromy] + weight) {
                dist[tox][toy] = dist[fromx][fromy] + weight;
            }
        }
    }

    for (int j = 0; j < Edges.size(); j++) {
        int fromx = Edges[j].first.first.first;
        int fromy = Edges[j].first.first.second;
        int tox = Edges[j].first.second.first;
        int toy = Edges[j].first.second.second;
        int weight = Edges[j].second;

        if (dist[fromx][fromy] == INT_MAX) continue;
        if (dist[tox][toy] > dist[fromx][fromy] + weight) {
            minusCycle = true;
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while (true) {
        cin >> W >> H;
        memset(grid, 0, sizeof(grid));
        memset(grave, 0, sizeof(grave));
        memset(hole, 0, sizeof(hole));
        Edges.clear();
        minusCycle = false;
        for (int x = 0; x < W; x++) {
            for (int y = 0; y < H; y++) {
                dist[x][y] = INT_MAX;
            }
        }

        if (W == 0 && H == 0) break;
        cin >> G;
        for (int i = 1; i <= G; i++) {  // 무덤의 위치
            cin >> X >> Y;
            grave[X][Y] = true;
        }

        cin >> E;
        for (int i = 1; i <= E; i++) {
            cin >> X1 >> Y1 >> X2 >> Y2 >> T;
            hole[X1][Y1] = true;
            Edges.push_back(
                make_pair(make_pair(make_pair(X1, Y1), make_pair(X2, Y2)), T));
            // x1,y1에서 x2,y2로 t시간만에 나온다.
        }

        for (int x = 0; x < W; x++) {
            for (int y = 0; y < H; y++) {
                if (x == (W - 1) && y == (H - 1)) continue;
                if (grave[x][y] || hole[x][y]) continue;
                for (int k = 0; k < 4; k++) {
                    tempx = x + dx[k];
                    tempy = y + dy[k];
                    if (is_ok(tempx, tempy)) {
                        Edges.push_back(make_pair(
                            make_pair(make_pair(x, y), make_pair(tempx, tempy)),
                            1));
                    }
                }
            }
        }

        // cout << "testcase " << '\n';
        dist[0][0] = 0;
        // debug();
        bellmanford();

        if (minusCycle) {
            cout << "Never" << '\n';
        } else {
            if (dist[W - 1][H - 1] == INT_MAX) {
                cout << "Impossible" << '\n';
            } else
                cout << dist[W - 1][H - 1] << '\n';
        }
    }
}