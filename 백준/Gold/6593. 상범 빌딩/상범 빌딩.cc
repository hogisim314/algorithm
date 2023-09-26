#include <iostream>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;

int di[] = {1,0,0,-1,0,0};
int dj[] = {0,1,0,0,-1,0};
int dk[] = {0,0,1,0,0,-1};
char building[33][33][33];
int minute[33][33][33];
int si,sj,sk,ei,ej,ek;
int l,r,c;
queue<pair<pair<int, int>, int> > q;

bool is_ok(int i, int j, int k) {
    if (i<1 || i>r || j<1 || j>c || k<1 || k>l || minute[i][j][k]>=0 || building[i][j][k] == '#') return false;
    else return true;
}

void BFS() {
    q.push(make_pair(make_pair(si,sj),sk));
    while(!q.empty()) {
        int topi = q.front().first.first;
        int topj = q.front().first.second;
        int topk = q.front().second;
        int count = minute[topi][topj][topk];
        q.pop();
        for (int i=0; i<6; i++) {
            int ti = topi + di[i];
            int tj = topj + dj[i];
            int tk = topk + dk[i];
            if (is_ok(ti,tj,tk)) {
                q.push(make_pair(make_pair(ti,tj),tk));
                minute[ti][tj][tk]=count+1;
            }
        }
    }
}

int main() {
    while(true) {
        memset(building,0,sizeof(building));
        memset(minute,-1,sizeof(minute));
        cin>>l>>r>>c;
        if (l==0 && r==0 && c==0) {
            break;
        }
        for (int k=1; k<=l; k++) {
            for (int i=1; i<=r; i++) {
                for (int j=1; j<=c; j++) {
                    cin>>building[i][j][k];
                    if (building[i][j][k]=='S') {
                        si=i;
                        sj=j;
                        sk=k;
                        minute[i][j][k] = 0;
                    }
                    if (building[i][j][k]=='E') {
                        ei=i;
                        ej=j;
                        ek=k;
                    }
                }
            }
        }
        BFS();

        // for (int k=1; k<=l; k++) {
        //     for (int i=1; i<=r; i++) {
        //         for (int j=1; j<=c; j++) {
        //             cout<<minute[i][j][k]<<' ';
        //         }
        //         cout<<'\n';
        //     }
        //     cout<<'\n';
        // }

        if (minute[ei][ej][ek]==-1) {
            cout<<"Trapped!"<<'\n';
        } else {
            cout<<"Escaped in "<<minute[ei][ej][ek]<<" minute(s)."<<'\n';
        }
    }
    return 0;
}