#include <stdio.h>
int dp[33][33];

int main() {
	int TestCase, m, n;
	scanf("%d", &TestCase);

  for (int i=0; i<=30; ++i) {
    dp[i][0]=1;
    dp[i][i]=1;
  }

  for (int i=2; i<=30; ++i) {
    for (int j=1; j<=30; ++j) {
      dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
    } 
  }

	for (int q = 1; q <= TestCase; q++) {
		scanf("%d%d", &n, &m); //mCr 순서--함수 가서도 aCb순서
		printf("%d\n", dp[m][n]);
	}
	return 0;
}