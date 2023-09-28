#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <memory.h>
#include <algorithm>
using namespace std;
int tc;
int n;
int cnt;
int choose[100100];
bool visited1[100100]; // 방문시작
bool visited2[100100]; // 사이클시작
int group[100100];

void solve(int n)
{
    stack<int> s;
    int cur = n;
    int next;
    while (true) {
        visited1[cur] = true;
        next = choose[cur];
        s.push(cur);
        
        if (group[next]==-1 && visited1[next]) { // phase2 시작
            stack<int> phase2;
            cur = next;
            visited2[cur]=true;
            phase2.push(cur);
            while(true) {
                next = choose[cur];
                if (visited2[next]) { //visited2 true이면 사이클 끝.
                    int king = phase2.top();
                    while(!phase2.empty()) {
                        group[phase2.top()] = king;
                        phase2.pop();
                    }
                    break;
                }
                visited2[next]=true;
                phase2.push(next);
                cur = next;
            }
            while(!s.empty()) {
                if (group[s.top()]==-1) {
                    group[s.top()]=0;
                }
                s.pop();
            }
            break;
        }
        else if (group[next]>=0) {
            while(!s.empty()) {
                if (group[s.top()]==-1) {
                    group[s.top()]=0;
                }
                s.pop();
            }
            break;
        }
        cur = next;
    }
}

int main()
{
    cin >> tc;
    while (tc--)
    {
        cnt=0;
        memset(group, -1, sizeof(group));
        memset(visited1,0,sizeof(visited1));
        memset(visited2,0,sizeof(visited1));
        memset(choose,0,sizeof(visited1));
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> choose[i];
        }
        for (int i = 1; i <= n; i++)
        {
            if (group[i] == -1)
            {
                solve(i);
            }
        }
        for (int i=1; i<=n; i++) {
            if (group[i] <=0) {
                cnt++;
            }
        }
        cout<<cnt<<'\n';
    }
}
