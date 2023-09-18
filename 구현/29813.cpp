#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;
string init;
int ID;
int N;
deque<pair<string, int> > dq;
int main() {
    cin>>N;
    for (int i=0; i<N; i++) {
        cin>>init>> ID;
        dq.push_back({init, ID});
    }

    if (N==1) {
        cout<<dq.front().first;
        return 0;
    }
    while(dq.size()>1) {
        int X = dq.front().second%100;
        dq.pop_front();
        X=X-1;
        while(X--) {
            dq.push_back(dq.front());
            dq.pop_front();
        }
        dq.pop_front();
    }
    cout<<dq.front().first;
}