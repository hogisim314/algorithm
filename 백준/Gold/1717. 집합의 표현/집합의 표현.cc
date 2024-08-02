#include <algorithm>
#include <iostream>
using namespace std;
int n, m;
int parent[1111111];
int cmd, a, b;

int Find(int x) {
    if (x == parent[x]) {
        return x;
    }
    return parent[x] = Find(parent[x]);
}

void Union(int a, int b) { parent[Find(a)] = Find(b); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < m; i++) {
        cin >> cmd >> a >> b;
        if (cmd == 0) {  // union
            Union(a, b);
        } else if (cmd == 1) {  // find
            if (Find(a) == Find(b)) {
                cout << "YES" << '\n';
            } else {
                cout << "NO" << '\n';
            }
        }
    }
}