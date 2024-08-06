#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
int V, E;
vector<int> nodes[100100];
int discover[100100];
set<pair<int, int> > s;
int u, v;
int cnt = 0;
int dfs(int node, int parent) {
    discover[node] = ++cnt;
    int num = discover[node];
    int child = 0;
    for (int i = 0; i < nodes[node].size(); i++) {
        int next = nodes[node][i];

        if (next == parent)  // 부모 정점으로 가는 간선은 제외
            continue;
        if (discover[next] == 0) {
            child++;
            int low = dfs(next, node);
            num = min(num, low);
            if (low > discover[node]) {
                s.insert(make_pair(min(node, next), max(node, next)));
            }
        } else {
            num = min(num, discover[next]);
        }
    }
    return num;
}

int main() {
    cin >> V >> E;
    for (int i = 1; i <= E; i++) {
        cin >> u >> v;
        nodes[u].push_back(v);
        nodes[v].push_back(u);
    }
    for (int i = 1; i <= V; i++) {
        if (discover[i] == 0) {
            dfs(i, 0);
        }
    }
    cout << s.size() << '\n';
    for (auto itr = s.begin(); itr != s.end(); itr++) {
        cout << itr->first << ' ' << itr->second << '\n';
    }
}