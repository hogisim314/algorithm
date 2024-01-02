#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n, m;
int a, b;
bool found = false;
vector<int> friends[2002];
bool visited[2002];

void backtracking(int num, int depth) {
    visited[num] = true;
    if (depth == 5) {
        found = true;
        return;
    }
    for (int i = 0; i < friends[num].size(); i++) {
        if (visited[friends[num][i]]) continue;
        backtracking(friends[num][i], depth + 1);
        visited[friends[num][i]] = false;
    }
    visited[num] = false;
    return;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        friends[a].push_back(b);
        friends[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        backtracking(i, 1);
    }

    if (found) {
        cout << 1;
    } else {
        cout << 0;
    }
    return 0;
}