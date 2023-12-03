#include <iostream>
using namespace std;
int n;
int ans;
int main() {
    cin>>n;
    for (int i=0; i<=(n/3); i++) {
        if ((n-(3*i))%5==0) {
            ans+=i;
            ans+=(n-(3*i))/5;
            cout<<ans;
            return 0;
        }
    }
    cout<<-1;
    return 0;
}