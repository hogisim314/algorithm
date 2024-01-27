#include <string>
#include <vector>
#include <iostream>
#define mod 1000000007;

using namespace std;

int arr[105][105];
long long dp[105][105];

int solution(int m, int n, vector<vector<int>> puddles) {
    long long answer = 0;
    dp[1][1] = 1;
    for (int i=0; i<puddles.size(); i++) {
        arr[puddles[i][0]][puddles[i][1]] = -1;
    }
    
    for (int j=1; j<=n; j++) {
        for (int i=1; i<=m; i++) {
            if (arr[i][j] == -1) continue;
            if (i>=2) {
                dp[i][j]+=dp[i-1][j];
                dp[i][j]%=mod;
            }
            if (j>=2) {
                dp[i][j]+=dp[i][j-1];
                dp[i][j]%=mod;
            }
        }
    }
    
    answer = dp[m][n];
    
    return answer%mod;
}