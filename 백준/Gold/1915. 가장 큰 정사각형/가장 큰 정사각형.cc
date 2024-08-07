#include <iostream>
#include <algorithm>
using namespace std;
int map[1111][1111];
int psum[1111][1111];
int n, m;
int main() {
  cin>>n>>m;
  for (int i=1; i<=n; ++i) {
    for (int j=1; j<=m; ++j) {
      scanf("%1d", &map[i][j]);
    }
  }
  for (int i=1; i<=n; ++i) {
    for (int j=1; j<=m; ++j) {
      psum[i][j]=psum[i-1][j]+psum[i][j-1]-psum[i-1][j-1]+map[i][j];
    }
  }

  int ans=0;
  for (int i=1; i<=n; ++i) {
    for (int j=1; j<=m; ++j) {
      //게임판의 숫자가 1이라면
      if (map[i][j]==1) {
        int res=1;
        int idx=1;

        while(i+idx<=n&&j+idx<=m) {
          //특정 두 지점 사이의 부분 합
          int space = psum[i+idx][j+idx]-psum[i+idx][j-1]-psum[i-1][j+idx]+psum[i-1][j-1];

          idx++;

          if (space!=idx*idx) break;

          res=idx*idx;
        }
        ans=max(ans,res);
      }
    }
  }
  cout<<ans;
}