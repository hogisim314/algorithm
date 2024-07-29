#include <iostream>
#include <algorithm>
using namespace std;

long long arr[111111];
long long want_find[111111];

long long searching(long long LEFT, long long RIGHT,long long finding) {
  long long MID = (LEFT+RIGHT)/2;
  if (arr[MID]==finding) return 1;

  if (arr[LEFT]<=finding&&finding<=arr[MID]) {
    return searching(LEFT,MID, finding);
  }
  else if (arr[MID+1]<=finding&&finding<=arr[RIGHT]) {
    return searching(MID+1, RIGHT, finding);
  }
  return 0;
}

int main() {
  long long n;
  cin>>n;
  for (long long i=0; i<n; ++i) {
    cin>>arr[i];
  }
  sort(arr, arr+n);

  long long m;
  cin>>m;
  for (long long i=0; i<m; ++i) {
    cin>>want_find[i];
  }

  for (long long i=0; i<m; ++i) {
    cout<<searching(0, n-1, want_find[i])<<'\n';
  }
}