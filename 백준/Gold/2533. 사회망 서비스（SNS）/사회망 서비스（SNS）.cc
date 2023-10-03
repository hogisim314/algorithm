#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int vertex1, vertex2;
vector<int> v[1000100];
int dp[1000100][2];//0이 ea일때 1이 ea가 아닐때
bool visited[1000100];

void DFS(int node) {
    visited[node] = true;
    for (int i=0; i<v[node].size(); i++) {
        int child_node = v[node][i];
        if (!visited[child_node]) {
            DFS(child_node);
            dp[node][0] += min(dp[child_node][0], dp[child_node][1]);
            dp[node][1] += dp[child_node][0];
        }
    }
}

int main() {
    cin>>n;
    for (int i=1; i<=n-1; i++) {
        cin>>vertex1>>vertex2;
        v[vertex1].push_back(vertex2);
        v[vertex2].push_back(vertex1);
    }

    for (int i=1; i<=n; i++) {
        dp[i][0] = 1;
        sort(v[i].begin(), v[i].end());
    }

    DFS(1);
    cout<<min(dp[1][0], dp[1][1]);
}