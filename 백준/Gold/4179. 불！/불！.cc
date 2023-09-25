#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;
int r,c;
char miro[1111][1111];
vector<pair<int, int> > fire;
int fire_time[1111][1111];
int jihoon_time[1111][1111];
bool is_outdoor[1111][1111];
int jihoon_i, jihoon_j;
int ans = 987654321;
int di[] = {1,0,-1,0};
int dj[] = {0,1,0,-1};

bool move_ok_fire(int i, int j) {
    if (i<1 || i>r || j<1 || j>c || miro[i][j] == '#' || miro[i][j] == 'F' || fire_time[i][j] !=0) return false;
    else return true;
}

bool move_ok_jihoon(int i, int j) {
    if (i<1 || i>r || j<1 || j>c || miro[i][j] == '#' || miro[i][j] == 'F' || miro[i][j] == 'J' || jihoon_time[i][j]!=-1 ) return false;
    else return true;
}
// void fire_move() {
//     int curi, curj;
//     for (int i=0; i<fire.size(); i++) {
//         curi = fire[i].first;
//         curj = fire[i].second;
//         for (int k=0; k<4; k++) {
//             int ti = curi+di[k];
//             int tj = curj+dj[k];
//             if (move_ok_fire(ti,tj)) {//fire move
//                 miro[ti][tj] = 'F';
//                 fire.push_back(make_pair(ti,tj));
//             }
//         }
//     }
// }

void fire_move() {
    queue<pair<int, int> > fire_q;
    for (int i=0; i<fire.size(); i++) {
        fire_q.push(make_pair(fire[i].first, fire[i].second));
    }
    while(!fire_q.empty()) {
        int topi = fire_q.front().first;
        int topj = fire_q.front().second;
        fire_q.pop();
        int minute = fire_time[topi][topj];
        for (int k=0; k<4; k++) {
            int ti = topi + di[k];
            int tj = topj + dj[k];
            if (move_ok_fire(ti,tj)) {
                fire_q.push(make_pair(ti,tj));
                fire_time[ti][tj] = minute+1;
            }
        }
    }
}

void jihoon_move() {
    queue<pair<int, int> > jihoon_q;
    jihoon_q.push(make_pair(jihoon_i, jihoon_j));

    while(!jihoon_q.empty()) {
        int topi = jihoon_q.front().first;
        int topj = jihoon_q.front().second;
        int minute = jihoon_time[topi][topj];
        jihoon_q.pop();
        for (int k=0; k<4; k++) {
            int ti = topi + di[k];
            int tj = topj + dj[k];
            if (move_ok_jihoon(ti,tj)) {
                if (fire_time[ti][tj]==0 || (fire_time[ti][tj]!=0 && fire_time[ti][tj]>jihoon_time[topi][topj]+1)) {
                    jihoon_q.push(make_pair(ti,tj));
                    jihoon_time[ti][tj] = minute+1;
                }
            }
        }

    }
}

int main() {
    cin>>r>>c;
    memset(jihoon_time, -1, sizeof(jihoon_time));
    for (int i=1; i<=r; i++) {
        for (int j=1; j<=c; j++) {
            cin>>miro[i][j];
            if (miro[i][j]=='F') {
                fire.push_back(make_pair(i,j));
                fire_time[i][j] = 0;
            }
            else if (miro[i][j] == 'J') {
                jihoon_i = i;
                jihoon_j = j;
                jihoon_time[i][j] = 0;
            }
        }
    }

    fire_move();
    jihoon_move();
//    for (int i=1; i<=r; i++) {
//        for (int j=1; j<=c; j++) {
//            cout<<fire_time[i][j] <<' ';
//        }
//        cout<<'\n';
//    }
//
//    for (int i=1; i<=r; i++) {
//        for (int j=1; j<=c; j++) {
//            cout<<jihoon_time[i][j] <<' ';
//        }
//        cout<<'\n';
//    }
    
    for (int i=1; i<=r; i++) {
        for (int j=1; j<=c; j++) {
            if ((miro[i][j] == 'J' || miro[i][j] == '.') && (i==1 || i==r || j==1 || j==c) ) {
                if (jihoon_time[i][j] != -1 ) {
                    ans = min (ans, jihoon_time[i][j]);
                }
            }
        }
    }
    if (ans == 987654321) {
        cout<<"IMPOSSIBLE";
    }
    else cout<<ans+1;
    return 0;

    // queue<pair<pair<int, int> , int> > q; //세번째 인자는 몇분 움직였는지
    // q.push(make_pair(make_pair(jihoon_i, jihoon_j),0));
    // while(!q.empty()) {
    //     for (int k=0; k<4; k++) {
    //         int ti = q.front().first.first + di[k];
    //         int tj = q.front().first.second + dj[k];
    //         int count = q.front().second;
    //         if (move_ok_fire(ti,tj)) {
    //             q.push(make_pair(make_pair(ti,tj),second));
    //         }
    //     }


    // }
}
