#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n;
int x, y;
vector<pair<int, int> > v;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    for (int i = 0; i < n; i++) {
        int cnt = 1;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (v[j].first > v[i].first && v[j].second > v[i].second) {
                cnt++;
            }
        }
        cout << cnt << ' ';
    }
}