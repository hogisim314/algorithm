#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> node[202];
bool visited[202];
void dfs(int v) {
    for (int i=0; i<node[v].size(); i++) {
        if (!visited[node[v][i]]) {
            visited[node[v][i]]=true;
            dfs(node[v][i]);
        }
    }
    return;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (computers[i][j] == 1) {
                node[i].push_back(j);
                node[j].push_back(i);
            }
        }
    }
    
    for (int i=0; i<n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            answer++;
            dfs(i);
        }
    }
    
    return answer;
}