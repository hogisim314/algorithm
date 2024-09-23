#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int N, D;

class shortCut {
   public:
    int st;
    int ed;
    int dist;

    shortCut() {}
    shortCut(int st, int ed, int dist) {
        this->st = st;
        this->ed = ed;
        this->dist = dist;
    }
};
int s, e, d;
int dp[10005];
vector<shortCut> scs;
int main() {
    cin >> N >> D;
    for (int i = 1; i <= N; ++i) {
        cin >> s >> e >> d;
        scs.push_back(shortCut(s, e, d));
    }

    for (int i = 1; i <= D; ++i) {
        dp[i] = dp[i - 1] + 1;
        for (int j = 0; j < N; ++j) {
            if (i == scs[j].ed) {
                dp[i] = min(dp[i], dp[scs[j].st] + scs[j].dist);
            }
        }
    }
    cout << dp[D];
}