#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int n,num;
int si[200200];
int ti[200200];
priority_queue<int> pq;
vector<pair<int, int> > lecture;
int main() {
    cin>>n;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for (int i=1; i<=n; i++) {
        cin>>num>>si[i]>>ti[i];
        lecture.push_back(make_pair(si[i], ti[i]));
    }
    
    sort(lecture.begin(), lecture.end());

    for (int i=0; i<lecture.size(); i++) {
        if (pq.empty()) {
            pq.push(-lecture[i].second);
        }
        else {
            if (-pq.top()<=lecture[i].first) {
                pq.pop();
                pq.push(-lecture[i].second);
            }
            else {
                pq.push(-lecture[i].second);
            }
        }
    }
    cout<<pq.size();
}

