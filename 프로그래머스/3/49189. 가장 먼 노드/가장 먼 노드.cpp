#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <queue>
using namespace std;

vector<int> node[20002];
int dist[20002];
int visited[20002];
int top, maxx=0, cnt;
int nodeNum;
void bfs() {
    memset(visited, -1, sizeof(visited));
    queue<int> q;
    visited[1] = 0;
    q.push(1);
    
    while(!q.empty()) {
        top = q.front();
        q.pop();
        
        for (int i=0; i<node[top].size(); i++) {
            if (visited[node[top][i]]==-1) {
                visited[node[top][i]] = visited[top]+1;
                q.push(node[top][i]);
            }
        }
    }
}

void count_max() {
    for (int i=1; i<=nodeNum; i++) {
        cout<<visited[i]<<' ';
        if (visited[i]>maxx) {
            maxx = visited[i];
            cnt=1;
        }
        else if (visited[i]==maxx) {
            cnt++;
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    nodeNum=n;
    for (int i=0; i<edge.size(); i++) {
        node[edge[i][0]].push_back(edge[i][1]);
        node[edge[i][1]].push_back(edge[i][0]);
    }
    
    bfs();
    count_max();
    
    answer = cnt;
    
    return answer;
}