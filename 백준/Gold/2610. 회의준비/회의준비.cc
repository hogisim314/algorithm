#include <limits.h>

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N, M;
int a, b;
int setCnt;
int parent[111];  // i의 부모는 parent[i]
int dist[111][111];
bool visited[111];

int Find(int num) {
    if (num == parent[num]) {  // 종료조건
        return num;
    }
    return parent[num] = Find(parent[num]);
}
void Union(int n1, int n2) { parent[Find(n1)] = Find(n2); }  // n1을 n2에 편입

vector<int> dSet[111];  // disjointset의미
vector<int> root;       // 루트들만 모아놓았음.
vector<int> represent;  // 위원회 별 대표
int idx = 1;            // 모임세는 인덱스

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dist[i][j] = 10000;
        }
    }

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        dist[a][b] = 1;
        dist[b][a] = 1;
        dist[a][a] = 0;
        dist[b][b] = 0;
        Union(a, b);
    }

    for (int i = 1; i <= N; i++) {
        if (parent[i] == i) {
            setCnt++;
            root.push_back(i);
        }
    }

    cout << setCnt << '\n';

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 0; i < root.size(); i++) {
        int r = root[i];
        for (int j = 1; j <= N; j++) {
            if (Find(j) == r) {
                dSet[idx].push_back(j);
            }
        }
        idx++;
    }

    // for (int i = 0; i < idx; i++) {
    //     for (int j = 0; j < dSet[i].size(); j++) {
    //         cout << dSet[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    // for (int i = 1; i <= N; i++) {
    //     for (int j = 1; j <= N; j++) {
    //         cout << dist[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    for (int i = 1; i < idx; i++) {
        int minTime = 987654321;
        int repr = 0;
        for (int j = 0; j < dSet[i].size(); j++) {
            int maxDist = 0;
            for (int k = 0; k < dSet[i].size(); k++) {
                if (j == k) continue;
                // cout << i << ' ' << j << ' ' << k << ' '
                //      << dist[dSet[i][j]][dSet[i][k]] << '\n';
                maxDist = max(maxDist, dist[dSet[i][j]][dSet[i][k]]);
            }
            if (minTime > maxDist) {
                minTime = maxDist;
                repr = dSet[i][j];
                // cout << "repr " << repr << " minTime " << minTime << '\n';
            }
        }
        if (repr == 0) {
            // cout << i << ' ';
            cout << "error";
        }
        represent.push_back(repr);
    }
    sort(represent.begin(), represent.end());
    for (int i = 0; i < represent.size(); i++) {
        cout << represent[i] << '\n';
    }
}