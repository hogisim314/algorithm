#include <algorithm>
#include <cmath>
#include <memory.h>
#include <iostream>
#include <vector>
using namespace std;
int tc, N;
int cr, cc, hr, hc;

vector<pair<int, int> > customers;
bool visited[12];
int r, c;
int parr[12];
int globalAns = 987654321;
int localAns;

int get_dist(int i1, int j1, int i2, int j2) {
    return abs(i1 - i2) + abs(j1 - j2);
}

void permu(int level) {
    if (level == N) {
        localAns = 0;
        int str, stc, edr, edc;
        str = cr;
        stc = cc;
        for (int i = 0; i < N; ++i) {
            // cout << parr[i] << ' ';
            edr = customers[parr[i]].first;
            edc = customers[parr[i]].second;
            int d = get_dist(str, stc, edr, edc);
            localAns += d;
            str = edr;
            stc = edc;
        }
        int d = get_dist(str, stc, hr, hc);
        localAns += d;
        // cout << localAns << '\n';
        globalAns = min(globalAns, localAns);
        return;
    }

    for (int i = 0; i < N; ++i) {
        if (visited[i]) continue;
        visited[i] = true;
        parr[level] = i;
        permu(level + 1);
        visited[i] = false;
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> tc;
    for (int t = 1; t <= tc; ++t) {
        globalAns = 987654321;
        customers.clear();
        memset(visited, 0, sizeof(visited));
        cin >> N;
        cin >> cr >> cc >> hr >> hc;
        for (int i = 1; i <= N; ++i) {
            cin >> r >> c;
            customers.emplace_back(make_pair(r, c));
        }
        permu(0);
        cout << "#" << t << ' ' << globalAns << '\n';
    }
}