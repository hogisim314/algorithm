#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string s;
string tmp;
vector<string> str;
bool dp[101];
int n;

bool is_in(string slice) {
    for (int i=0; i<n; i++) {
        if (str[i] == slice) {
            return true;
        }
    }
    return false;
}

int main() {
    cin>>s;
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>tmp;
        str.push_back(tmp);
    }
    
    for (int i=0; i<s.size(); i++) {
        for (int j=0; j<i; j++) {
            if (dp[j]) {
                if (is_in(s.substr(j+1,i-j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        if (is_in(s.substr(0,i+1))) {
            dp[i] = true;
        }
    }
    
    if (dp[s.size()-1]) cout<<1;
    else cout<<0;
}
