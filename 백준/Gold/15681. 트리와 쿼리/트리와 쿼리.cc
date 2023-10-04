#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,r,q,u;
int v1,v2;
vector<int> v[100100];
bool visited[100100];
int dp[100100];

void DFS(int node) {
    visited[node] = true;
    for (int i=0; i<v[node].size(); i++) {
        int child_node = v[node][i];
        if (!visited[child_node]) {
            DFS(child_node);
            dp[node]+=dp[child_node];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>r>>q;
    for (int i=0; i<n-1; i++) {
        cin>>v1>>v2;
        v[v1].push_back(v2);
        v[v2].push_back(v1);
        dp[v1] = 1;
        dp[v2] = 1;
    }

    DFS(r);

    for  (int i=0; i<q; i++) {
        cin>>u;
        cout<<dp[u]<<'\n';
    }
}