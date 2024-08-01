#include <iostream>
using namespace std;
int n;
bool sieve[10000111];
int main() {
  cin>>n;
  if (n==1) return 0;
  for (int p=2; p*p<=n; ++p) {
    if (n%p==0) {
      while(n%p==0) {
        cout<<p<<'\n';
        n/=p;
      }
    }
  }
  if (n!=1) {
    cout<<n<<'\n';
  }
}