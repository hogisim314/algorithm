#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
int k;
int money[111111];
int maxx = -1;
int low, high,mid,cnt,cur, sum, result;

void f() {
    for (int i=0; i<n; i++) {
        if (cur<money[i]) {
            cur = mid;//출금
            cnt++;
            cur-=money[i];
        }
        else if (cur>=money[i]) {
            cur-=money[i];
        }
        
    }
}

int main() {
    cin>>n>>m;
    for (int i=0; i<n; i++) {
        cin>>money[i];
        maxx = max(maxx, money[i]);
        sum+=money[i];
    }
    low = maxx;
    high = sum;
    while(low<=high) {
        cnt=0;
        mid = (low+high)/2;
        cur = 0;
        f();
        if (cnt>m) {
            low = mid+1;
        }
        else if (cnt<=m) {
            result = mid;
            high = mid-1;
        }
    }
    cout<<result;
}
