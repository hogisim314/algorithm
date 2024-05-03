#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        vector<string> list;
        string temp;
        string ans;
        int i=0;
        while(true) {
            if (i==s.size()) {
                if (temp!="") {
                    list.push_back(temp);
                }
                break;
            }
            if (s[i]==' ') {
                if (temp!="") {
                    list.push_back(temp);
                    temp="";
                }
            }
            else {
                temp+=s[i];
            }
            i++;
        }
        // for (int i=0; i<list.size(); i++) {
        //     cout<<list[i]<<' ';
        // }
        for (int i=list.size()-1; i>=1; i--) {
            ans+=list[i];
            ans+=" ";
        }
        ans+=list[0];
        return ans;
    }
};