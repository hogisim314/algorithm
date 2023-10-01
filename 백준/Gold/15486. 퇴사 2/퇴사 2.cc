#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int ti[1500100];
int pi[1500100];
int ei[1500100];
int dp[1500100];
int maxx;
int main() {
    cin>>n;
    for (int i=1; i<=n; i++) {
        cin>>ti[i]>>pi[i];
    }

    for (int i=1; i<=n+1; i++) {
        maxx = max(maxx, dp[i]);
        if (i+ti[i]<=n+1) {
            dp[i+ti[i]]=max(maxx+pi[i], dp[i+ti[i]]);
        }
        
    }

    cout<<maxx;
}
