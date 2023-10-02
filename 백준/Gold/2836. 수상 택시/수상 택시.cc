#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,a,b,m;
long long ans;
vector<pair<int, int> > v1;
vector<pair<int, int> > v2;
vector<pair<int, int> > loc1;
vector<pair<int, int> > loc2;
int cur_idx;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for (int i=1; i<=n; i++) {
        cin>>a>>b;
        if (a<b) {
            loc1.push_back(make_pair(a,b));
        } else if (a>b) {
            loc2.push_back(make_pair(b,a));
        }
    }
    sort(loc1.begin(), loc1.end());
    sort(loc2.begin(), loc2.end());

    // loc1[0].first=0;
    // loc1[loc1.size()-1].second = m;
    // for (int i=0; i<loc1.size(); i++) {
    //     if (v1.empty()) {
    //         v1.push_back(make_pair(loc1[i].first, loc1[i].second));
    //         cur_idx=0;
    //     }
    //     else {
    //         if (v1[cur_idx].first<=loc1[i].first && loc1[i].first<=v1[cur_idx].second) {
    //             v1[cur_idx].first = min(v1[cur_idx].first, loc1[i].first);
    //             v1[cur_idx].second = max(v1[cur_idx].second, loc1[i].second);
    //         } else {
    //             v1.push_back(make_pair(loc1[i].first, loc1[i].second));
    //             cur_idx++;
    //         }
    //     }
    // }

    for (int i=0; i<loc2.size(); i++) {
        if (v2.empty()) {
            v2.push_back(make_pair(loc2[i].first, loc2[i].second));
            cur_idx=0;
        }
        else {
            if (v2[cur_idx].first<=loc2[i].first && loc2[i].first<=v2[cur_idx].second) {
                v2[cur_idx].first = min(v2[cur_idx].first, loc2[i].first);
                v2[cur_idx].second = max(v2[cur_idx].second, loc2[i].second);
            } else {
                v2.push_back(make_pair(loc2[i].first, loc2[i].second));
                cur_idx++;
            }
        }
    }

    // for (int i=0; i<v1.size(); i++) {
    //     ans+=v1[i].second-v1[i].first;
    // }
    ans+=m;
    for (int i=0; i<v2.size(); i++) {
        ans+=2*(v2[i].second-v2[i].first);
    }
    cout<<ans;
}
