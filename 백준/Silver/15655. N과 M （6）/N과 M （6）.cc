#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
int parr[10];
int num[10];
void combi(int index, int nextIdx) {
    if (index==m) {
        for (int i=0; i<m; i++) {
            cout<<parr[i]<<' ';
        }
        cout<<'\n';
    }

    for (int i=nextIdx; i<n; i++) {
        parr[index] = num[i];
        combi(index+1, i+1);
    }
}

int main() {
    cin>>n>>m;
    for (int i=0; i<n; i++) {
        cin>>num[i];
    }
    sort(num, num+n);
    combi(0, 0);
}