#include <algorithm>
#include <iostream>
using namespace std;
int n, m;
int parr[10];
bool visited[10];
int num[10];
void permu(int depth) {
    if (depth == m) {
        for (int i = 0; i < m; i++) {
            cout << parr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        if (num[i] == parr[depth]) continue;
        visited[i] = true;
        parr[depth] = num[i];
        for (int j = depth + 1; j < m; j++) {
            parr[j] = 0;
        }
        permu(depth + 1);
        visited[i] = false;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort(num, num + n);
    permu(0);
}