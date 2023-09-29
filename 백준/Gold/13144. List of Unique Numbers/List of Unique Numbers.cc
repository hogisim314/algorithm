#include <iostream>
using namespace std;
int n;
int arr[100100];
bool visited[100100];
long long cnt;
int s,e;
int main() {
    cin>>n;
    for (int i=1; i<=n; i++) {
        cin>>arr[i];
    }
    e=1;
    for (int i=1; i<=n; i++) {
        s=i;
        while(e<=n && !visited[arr[e]]) {
            visited[arr[e]]=true;
            e++;
        }

        cnt +=(e-s);
        visited[arr[s]]=false;
    }

    cout<<cnt;
}
