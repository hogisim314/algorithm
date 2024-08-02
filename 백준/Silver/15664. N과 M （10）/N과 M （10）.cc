#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
int n, m;
int arr[15];
int parr[15];
set<vector<int> > s;
void combi(int depth, int lastIdx) {
    if (depth == m + 1) {
        vector<int> temp;
        for (int i = 1; i <= m; i++) {
            temp.push_back(parr[i]);
        }
        if (s.find(temp) != s.end()) {
            return;
        }
        s.insert(temp);
        for (int i = 0; i < temp.size(); i++) {
            cout << temp[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = lastIdx; i <= n; i++) {
        parr[depth] = arr[i];
        combi(depth + 1, i + 1);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    sort(arr + 1, arr + n + 1);
    combi(1, 1);
}