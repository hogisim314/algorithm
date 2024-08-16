#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n, m;
int cmd, a, b;
int parent[1000100];

int Find(int k) {  // 조상을 찾는
    if (parent[k] == k) {
        return k;
    }
    return parent[k] = Find(parent[k]);
}

void UNION(int a, int b) {
    int ancestorA = Find(a);
    int ancestorB = Find(b);
    parent[ancestorA] = ancestorB;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        cin >> cmd >> a >> b;
        if (cmd == 0) {
            // 합집합
            UNION(a, b);
        } else if (cmd == 1) {
            // 같은집합이니?
            if (Find(a) == Find(b)) {
                cout << "YES" << '\n';
            } else
                cout << "NO" << '\n';
        }
    }
}