#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
int s=1,e=1;
int arr[100100];
long long diff;
long long ans=2200000000;
int main() {
    cin>>n>>m;
    for (int i=1; i<=n; i++) {
        cin>>arr[i];
    }
    sort(arr+1, arr+n+1);

    while(s<n && e<=n && s<=e) {
        diff = arr[e]-arr[s];
        if (diff<m) {
            e++;
        }
        else {
            ans = min(ans, diff);
            s++;
        }
    }
    cout<<ans;
}
