#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int snow[606];
vector<pair<int, pair<int, int> > >snowsum;
int minn = 2000000001;
int idx1, idx2,idx3,idx4, sum1, sum2;
int ans;
int main() {
    cin>>n;
    for (int i=1; i<=n; i++) {
        cin>>snow[i];
    }
    
    for (int i=1; i<=n-1; i++) {
        for (int j=i+1; j<=n; j++) {
            snowsum.push_back(make_pair(snow[i]+snow[j], make_pair(i,j)));
        }
    }
    sort(snowsum.begin(), snowsum.end());
    
//    for (int i=0; i<snowsum.size(); i++) {
//        cout<<snowsum[i].first<<' '<<snowsum[i].second.first<<' '<<snowsum[i].second.second<<'\n';
//    }
    
    for (int i=0; i<snowsum.size()-1; i++) {
        sum1 = snowsum[i].first;
        sum2 = snowsum[i+1].first;
        idx1=snowsum[i].second.first;
        idx2=snowsum[i].second.second;
        idx3=snowsum[i+1].second.first;
        idx4=snowsum[i+1].second.second;
        
        if (idx1==idx3 || idx1==idx4 || idx2==idx3 || idx2==idx4) {
            continue;
        }
        
        if (abs(sum1-sum2)<abs(minn)) {
            ans = abs(sum1-sum2);
            minn = abs(sum1-sum2);
        }
    }
    cout<<ans;
}
