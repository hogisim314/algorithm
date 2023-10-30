#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <queue>
using namespace std;

int n,m;
int space[55][55];

int di[] = {0,-1,-1,-1,0,1,1,1};
int dj[] = {1,1,0,-1,-1,-1,0,1};
bool visited[55][55];
int dist[55][55];
int minn,maxx;

bool is_ok(int i, int j) {
    if (i<1 || i>n || j<1 || j>m || visited[i][j]) return false;
    else return true;
}

void bfs(int i, int j) {
    minn = 987654321;
    memset(visited,0,sizeof(visited));
    memset(dist, 0, sizeof(dist));
    queue<pair<int, int> > q;
    q.push(make_pair(i,j));
    visited[i][j] = true;
    int qff = q.front().first;
    int qfs = q.front().second;
    dist[qff][qfs] = 0;
    while(!q.empty()) {
        qff = q.front().first;
        qfs = q.front().second;
        q.pop();
        
        for (int k=0; k<8; k++) {
            int ti = qff+di[k];
            int tj = qfs+dj[k];
            if (is_ok(ti,tj)) {
                q.push(make_pair(ti,tj));
                dist[ti][tj] = dist[qff][qfs] + 1;
                visited[ti][tj] = 1;
            }
        }
    }

    for (int row=1; row<=n; row++) {
        for (int col=1; col<=m; col++) {
            if (row==i && col==j) continue;
            if (space[row][col]==1) {
                minn = min(minn, dist[row][col]);
            }
        }
    }
}

int main() {
    cin>>n>>m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin>>space[i][j];
        }
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (space[i][j]==0) {
                bfs(i,j);
                maxx = max(maxx, minn);
            }
        }
    }
    cout<<maxx;
}