#include <string>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;
int dp[32005];
vector<int> nums[10];
int tmp;
int numa, numb, big, small, quotient;
int solution(int n, int number) {
    int answer = 0;
    
    dp[n] = 1;
    nums[1].push_back(n);
    
    dp[n*10+n] = 2;
    nums[2].push_back(n*10+n);
    
    dp[(n*10+n)*10+n] = 3;
    nums[3].push_back((n*10+n)*10+n);
    
    dp[((n*10+n)*10+n)*10+n] = 4;
    nums[4].push_back(((n*10+n)*10+n)*10+n);
    
    if (n==1) {
        dp[11111]=5;
        nums[5].push_back(11111);
    }
    if (n==2) {
        dp[22222] = 5;
        nums[5].push_back(22222);
    }
    
    if (dp[n*n]==0) {
        nums[2].push_back(n*n);
        dp[n*n] = 2;
    }
    
    if (dp[n/n]==0) {
        nums[2].push_back(n/n);
        dp[n/n] = 2;
    }
    
    if (dp[n+n]==0) {
        nums[2].push_back(n+n);
        dp[n+n] = 2;
    }
    
    for (int i=3; i<=8; i++) {
        for (int j=1; j<=i/2; j++) {
            for (int a=0; a<nums[i-j].size(); a++) {
                numa = nums[i-j][a];
                for (int b=0; b<nums[j].size(); b++) {
                    numb = nums[j][b];
                    
                    if (numa==0 || numb ==0) continue;
                    if (numa*numb<=32000 && dp[numa*numb]==0) {//여기 * 말고도 +, - / 다 확인해봐야함.
                        nums[i].push_back(numa*numb);
                        dp[numa*numb]=i;
                    }
                    
                    if (numa+numb<=32000 && dp[numa+numb]==0) {//여기 * 말고도 +, - / 다 확인해봐야함.
                        nums[i].push_back(numa+numb);
                        dp[numa+numb]=i;
                    }
                    
                    if (dp[abs(numa-numb)]==0) {//여기 * 말고도 +, - / 다 확인해봐야함.
                        nums[i].push_back(abs(numa-numb));
                        dp[abs(numa-numb)]=i;
                    }
                    
                    big = max(numa, numb);
                    small = min(numa, numb);
                    quotient = (int)(big/small);
                    if (dp[quotient]==0) {//여기 * 말고도 +, - / 다 확인해봐야함.
                        nums[i].push_back(quotient);
                        dp[quotient]=i;
                    }
                }
            }
        }
    }
    
    if (dp[number]==0) {
        return -1;
    }
    else {
        return dp[number];
    }
    
    
    return answer;
}