#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
int n;
int arr[5050];
vector<int> res;
int s,e;
long long sum;
long long idx, sum12;
long long minn = 3000000000;//30억
int ans1, ans2, ans3;
int main() {
    cin>>n;
    for (int i=1; i<=n; i++) {
        cin>>arr[i];
    }
    sort(arr+1, arr+n+1);
    for (int i=1; i<=n-1; i++) {
        for (int j=i+1; j<=n; j++) {
            sum12 = arr[i]+arr[j];
            idx = lower_bound(arr+1, arr+n+1, -sum12)-arr;
            idx = idx==n+1 ? idx-1 : idx;
            
            sum = sum12 + arr[idx];
            if (idx>1) {
                long long temp = sum12+arr[idx-1];
                if (abs(temp)<abs(sum)) {
                    sum = temp;
                    idx = idx-1;
                }
            }
            if (i==idx || j==idx) {
                continue;
            }
            if (abs(sum)<abs(minn)) {
                ans1 = i;
                ans2 = j;
                ans3 = idx;
                minn = sum;
            }
        }
    }
    
    res.push_back(arr[ans1]);
    res.push_back(arr[ans2]);
    res.push_back(arr[ans3]);
    sort(res.begin(), res.end());
    cout<<res[0]<<' '<<res[1]<<' '<<res[2];
}
