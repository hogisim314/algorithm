#include <string>
#include <algorithm>
#include <memory.h>
#include <math.h>
#include <queue>
#include <vector>

using namespace std;

vector<int> maps[105];
bool visited[105];
int ans;

int BFS(int node) {
    queue<int> q;
    memset(visited, 0, sizeof(visited));
    int cnt=0;
    q.push(node);
    visited[node]=true;
    while(!q.empty()) {
        node = q.front();
        q.pop();
        for (int i=0; i<maps[node].size(); i++) {
            if (visited[maps[node][i]]) continue;
            else {
                visited[maps[node][i]]=true;
                cnt++;
                q.push(maps[node][i]);
            }
        }
    }
    return cnt;
}

int getDiff(int a, int b) { // a노드와 b를 잘랐을 때 송전탑 개수의 차이를 리턴.
    maps[a].erase(remove(maps[a].begin(), maps[a].end(), b), maps[a].end());
    maps[b].erase(remove(maps[b].begin(), maps[b].end(), a), maps[b].end());
    
    int numA=0, numB=0;
    
    numA = BFS(a);
    numB = BFS(b);
    
    return abs(numA-numB);
    
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 100;
    
    for (int i=0; i<wires.size(); i++) {
        maps[wires[i][0]].push_back(wires[i][1]);
        maps[wires[i][1]].push_back(wires[i][0]);
    }
    
    for (int i=0; i<wires.size(); i++) {
        int diff = getDiff(wires[i][0], wires[i][1]);

        answer = min(answer, diff);
        
        maps[wires[i][0]].push_back(wires[i][1]);
        maps[wires[i][1]].push_back(wires[i][0]);
    }
    
    return answer;
}