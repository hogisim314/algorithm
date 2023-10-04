#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int hp[22];
int happy[22];
int dp[22][111]; //dp[i][j] 에서 i명까지 봤을 때, 체력을 j까지 쓰는것 체력이 총 100까지 담을 수 있는 것. 
int main() {
    cin>>n;
    for (int i=1; i<=n; i++) {
        cin>>hp[i];
    }

    for (int i=1; i<=n; i++) {
        cin>>happy[i];
    }

    for (int i=0; i<=n; i++) {
        for (int j=0; j<100; j++) {
            if (i==0 || j==0) {
                dp[i][j] = 0;
            }
            else {
                if (hp[i]<=j) {
                    if (dp[i-1][j]<=dp[i-1][j-hp[i]]+happy[i]) {
                        dp[i][j] = dp[i-1][j-hp[i]] + happy[i];
                    } else {
                        dp[i][j] = dp[i-1][j];
                    }
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    }
    cout<<dp[n][99];
}