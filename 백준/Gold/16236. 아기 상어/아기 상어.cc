#include <iostream>
#include <vector>
#include <memory.h>
#include <queue>
#include <algorithm>
using namespace std;

int n;
bool needparent = false;
int di[] = {0,1,0,-1};
int dj[] = {1,0,-1,0};
int space[22][22];
bool visited[22][22];
int dmap[22][22];
int sharki, sharkj, sharksz=2;
int tick, minn,mini, minj, eatcnt;
bool cannotmove=false;

bool is_ok(int i, int j) {
    if (i<1 || i>n || j<1 || j>n || visited[i][j] || space[i][j] > sharksz) return false;
    return true;
}

void findAll() {
    needparent = true;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (space[i][j]<sharksz && space[i][j]>=1 && space[i][j] <=6) {
                needparent = false;
            }
        }
    }
}

bool Eatable(int i, int j) {
    if (space[i][j] < sharksz && space[i][j] >=1 && space[i][j] <=6) return true;
    else return false;
}

void getDistance() {
    memset(dmap, 0, sizeof(dmap)); // 거리 최대가 40이기 때문에 100으로 초기화하면 나중에 bfs로 도달 못한 거리 그대로 100 -> memset은 char은 이해함 근데 숫자는 이해못함!!! 고로 0으로 하자
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int> > q;
    q.push(make_pair(sharki, sharkj));
    int qff = q.front().first;
    int qfs = q.front().second;
    visited[qff][qfs] = true;
    dmap[sharki][sharkj] = 0;
    while(!q.empty()) {
        qff = q.front().first;
        qfs = q.front().second;
        q.pop();

        for (int i=0; i<4; i++) {
            int ti = qff + di[i];
            int tj = qfs + dj[i];
            if (is_ok(ti, tj)) {
                q.push(make_pair(ti,tj));
                dmap[ti][tj] = dmap[qff][qfs]+1;
                visited[ti][tj] = true;
            }
        }
    }
}

int main() {
    cin>>n;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin>>space[i][j];
            if (space[i][j] == 9) {
                sharki = i;
                sharkj = j;
                space[i][j] = 0;
            }
        }
    }

    while(!needparent) {
        minn = 450;
        findAll();
        if (needparent) {
            cout<<tick;
            return 0;
        }
        getDistance();
        cannotmove = true;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                if (i==sharki && j==sharkj) continue;
                if (dmap[i][j] >=1 && dmap[i][j] < minn && Eatable(i,j)) {
                    cannotmove = false;
                    minn = dmap[i][j];
                    mini = i;
                    minj = j;
                }
                else if (dmap[i][j] >=1 && dmap[i][j] == minn && Eatable(i,j)) {
                    if (i<mini) {// 더 위에 - i가 더 작아야 더 위에 있는거임.
                        mini = i;
                        minj = j;
                    }
                    else if (i==mini) { // 만약 같다?
                        if (j<minj) { // 더 왼쪽 - j가 더 작아야 더 왼쪽에 있는거임.
                            mini = i;
                            minj = j;
                        }
                    }
                    cannotmove = false;
                }
            }
        }
        if (cannotmove) {
            cout<<tick;
            return 0;
        }
        //이제 상어가 먹어야할 물고기와 거리를 알음.
        tick += dmap[mini][minj];
        space[mini][minj]=0;
        sharki = mini;
        sharkj = minj;
        eatcnt++;
        if (eatcnt == sharksz) {
            eatcnt = 0;
            sharksz++;
        }
    }
}
