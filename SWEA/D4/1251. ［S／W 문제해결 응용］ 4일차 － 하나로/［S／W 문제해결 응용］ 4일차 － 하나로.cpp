#include <memory.h>

#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;
int tc;
int n;
int x, y;
double e;

vector<pair<int, int> > Pos;
int parent[1111];
priority_queue<pair<double, pair<int, int> > > pq;
vector<pair<int, int> > adj[1111];
double ans = 0;
long long realans = 0;
double dist;
int node1, node2;

int Find(int u) {
    if (u == parent[u]) return u;

    return parent[u] = Find(parent[u]);
}

void Union(int u, int v) {
    int pu = Find(u);
    int pv = Find(v);

    if (pu == pv) return;
    parent[pv] = pu;
}

void prim() {
    while (!pq.empty()) {
        dist = -pq.top().first;
        node1 = pq.top().second.first;
        node2 = pq.top().second.second;
        pq.pop();
        if (Find(node1) == Find(node2)) continue;
        Union(node1, node2);
        ans += dist;
    }
}

void link() {
    for (int i = 0; i < Pos.size(); i++) {
        for (int j = i + 1; j < Pos.size(); j++) {
            dist = pow(Pos[i].first - Pos[j].first, 2) +
                   pow(Pos[i].second - Pos[j].second, 2);
            pq.push(make_pair(-dist * e, make_pair(i, j)));
            pq.push(make_pair(-dist * e, make_pair(j, i)));
        }
    }
    // cout << "pqsize " << pq.size() << '\n';
}

void init() {
    Pos.clear();
    memset(parent, 0, sizeof(parent));
    while (!pq.empty()) {
        pq.pop();
    }
    ans = 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        init();
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> x;
            Pos.emplace_back(x, 0);
            parent[i] = i;  // 얘도 그냥 같이 초기화
        }
        for (int i = 0; i < n; ++i) {
            cin >> y;
            Pos[i].second = y;
        }
        cin >> e;

        link();
        prim();
        cout << fixed;
        cout.precision(0);

        cout << "#" << t << ' ' << ans << '\n';
    }
}