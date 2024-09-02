#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n;
vector<pair<int, int> > v;
int jump = 5;
int main() {
    cin >> n;
    v.push_back(make_pair(1, 1));
    while (true) {
        int st = v[v.size() - 1].second + 1;
        int ed = st + jump;
        v.push_back(make_pair(st, ed));
        if (ed > 1000000000) break;
        jump += 6;
    }
    for (int i = 0; i < v.size(); i++) {
        int st = v[i].first;
        int ed = v[i].second;
        if (st <= n && n <= ed) {
            cout << i + 1;
            return 0;
        }
    }
}