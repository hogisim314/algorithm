#include <string>
#include <vector>

using namespace std;

int dp[555][555];
int maxx, sz;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    sz=triangle.size();
    dp[0][0] = triangle[0][0];
    for (int i=0; i<sz; i++) {
        dp[i][0] = dp[i-1][0] + triangle[i][0];
        for (int j=1; j<i; j++) {
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j])+triangle[i][j];
        }
        dp[i][i] = dp[i-1][i-1]+triangle[i][i];
    }
    
    for (int i=0; i<sz; i++) {
        maxx = max(maxx, dp[sz-1][i]);
    }
    return maxx;
}