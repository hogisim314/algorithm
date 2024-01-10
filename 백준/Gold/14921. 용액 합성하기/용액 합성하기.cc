#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
int n;
int arr[100005];
int low, high, mid, ans=200000000;
int main() {
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>arr[i];
    }
    for (int i=0; i<n-1; i++) {
        int sum = 0;
        int temp = 200000000;
        low = i+1;
        high = n-1;
        while(low<=high) {
            mid = (low+high)/2;
            sum = arr[i] + arr[mid];
            if (abs(sum)<=abs(temp)) {
                temp = sum;//더 작은게 있나 찾으러 가야 함.
            }
            //sum이 양수일 수 있고, 음수 일 수 있음. 어쨌든 절댓값을 낮춰야 한다. sum이 양수인데 절댓값이 더 크면 작은 값을 더해야 하고 sum이 음수인데 더 작으면 더 큰 값을 더해야 한다.
            if (sum<0) {
                low = mid+1;
            }
            else if (sum>0) {
                high = mid-1;
            }
            else if (sum==0) {
                ans = temp;
                cout<<ans;
                return 0;
            }
        }
        if (abs(temp)<=abs(ans)) {
            ans = temp;
        }
    }
    cout<<ans;
}
