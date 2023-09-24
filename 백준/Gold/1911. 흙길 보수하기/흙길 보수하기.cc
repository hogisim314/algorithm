#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,l;
int s, e;
int idx, ans;
int spos, epos, cnt, real_epos;
bool flag=false;
vector<pair<int, int> > pool;
int main() {
    cin>>n>>l;
    for (int i=0; i<n; i++) {
        cin>>s>>e;
        pool.push_back(make_pair(s,e));
    }
    sort(pool.begin(), pool.end());

    for (int i=0; i<pool.size(); i++) {
        if (flag==true) {
            spos = real_epos;
            flag = false;
        }
        else spos = pool[i].first;
        epos = pool[i].second;

        cnt = (epos-spos)%l==0 ? (epos-spos)/l : (epos-spos)/l+1;
        real_epos = spos + cnt * l;
        while(true) {
            if (real_epos <= pool[i].first) {
                i--;
                break;
            }
            else if (real_epos>pool[i].second) {
                i++;
                if (i>=pool.size()) {
                    break;
                }
            }
            else if (real_epos==pool[i].second) {
                break;
            }
            else if (real_epos<pool[i].second) {
                spos = real_epos;
                flag = true;
                i--;
                break;
            }
        }
        ans+=cnt;
    }
    cout<<ans;
}
