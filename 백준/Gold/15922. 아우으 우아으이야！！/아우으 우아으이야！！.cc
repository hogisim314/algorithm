#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,a,b;
int ans;
vector<pair<int, int> > v;
vector<pair<int, int> > draw;
int cur_idx;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for (int i=1; i<=n; i++) {
        cin>>a>>b;
        draw.push_back(make_pair(a,b));
    }
    sort(draw.begin(), draw.end());

    for (int i=0; i<draw.size(); i++) {
        if (v.empty()) {
            v.push_back(make_pair(draw[i].first, draw[i].second));
            cur_idx=0;
        }
        else {
            if (v[cur_idx].first<=draw[i].first && draw[i].first<=v[cur_idx].second) {
                v[cur_idx].first = min(v[cur_idx].first, draw[i].first);
                v[cur_idx].second = max(v[cur_idx].second, draw[i].second);
            } else {
                v.push_back(make_pair(draw[i].first, draw[i].second));
                cur_idx++;
            }
        }
    }

    for (int i=0; i<v.size(); i++) {
        ans+=v[i].second-v[i].first;
    }
    cout<<ans;
}
