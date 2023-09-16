#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string s;
vector<string> ans;
int main() {
    getline(cin, s);
    int idx = 0;
    string sub="";
    while(idx!=(s.size())) {
        if (s[idx]=='<') {
            while(s[idx]!='>') {
                sub.push_back(s[idx]);
                idx++;
            }
            sub.push_back(s[idx]);
            ans.push_back(sub);
            sub="";
        }
        else if (s[idx]==' ') {
            reverse(sub.begin(), sub.end());
            ans.push_back(sub+' ');
            sub="";
        }
        else sub.push_back(s[idx]);
        idx++;
        if (s[idx-1]!='>' && s[idx]=='<') {
            reverse(sub.begin(), sub.end());
            ans.push_back(sub);
            sub="";
        }
    }
    reverse(sub.begin(), sub.end());
    ans.push_back(sub);
    for (int i=0; i<ans.size(); i++) {
        cout<<ans[i];
    }
}
