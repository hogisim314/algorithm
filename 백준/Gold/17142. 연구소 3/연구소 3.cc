#include <memory.h>

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N, M;
int arr[55][55];
int virusCnt;
vector<pair<int, int> > virusLoc;
int di[] = {1, 0, -1, 0};
int dj[] = {0, 1, 0, -1};
int parr[10];
int globalAns = 987654321;
int emptyCnt;

void combi(int depth, int lastIdx) {
    if (depth == M) {
        // 다 고름.
        int localAns = 0;
        int visited[55][55];
        int localEmptyCnt = 0;
        memset(visited, 0, sizeof(visited));
        int topi, topj, nexti, nextj;
        queue<pair<int, int> > q;
        for (int i = 0; i < M; ++i) {
            // cout << parr[i] << ' ';
            int vi = virusLoc[parr[i]].first;
            int vj = virusLoc[parr[i]].second;
            visited[vi][vj] = 1;
            q.emplace(make_pair(vi, vj));
        }
        if (localEmptyCnt == emptyCnt) {
            globalAns = min(globalAns, localAns);
            return;
        }
        while (!q.empty()) {
            topi = q.front().first;
            topj = q.front().second;
            q.pop();

            for (int d = 0; d < 4; ++d) {
                nexti = topi + di[d];
                nextj = topj + dj[d];
                if (nexti < 1 || nexti > N || nextj < 1 || nextj > N ||
                    visited[nexti][nextj] > 0 || arr[nexti][nextj] == 1)
                    continue;
                visited[nexti][nextj] = visited[topi][topj] + 1;
                q.emplace(make_pair(nexti, nextj));
                if (arr[nexti][nextj] == 0) {
                    localEmptyCnt++;
                    localAns = max(localAns, visited[nexti][nextj] - 1);
                    if (localAns >= globalAns) return;
                }
                if (localEmptyCnt == emptyCnt) {
                    globalAns = min(globalAns, localAns);
                    return;
                }
            }
        }
        return;
    }

    for (int i = lastIdx; i < virusLoc.size(); ++i) {
        parr[depth] = i;
        combi(depth + 1, i + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) {
                virusCnt++;
                virusLoc.emplace_back(make_pair(i, j));
            } else if (arr[i][j] == 0) {
                emptyCnt++;
            }
        }
    }
    combi(0, 0);
    if (globalAns == 987654321) {
        cout << -1;
        return 0;
    }
    cout << globalAns;
}