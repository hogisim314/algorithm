#include <iostream>
#include <string>
#include <algorithm>
#include <string>

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans="";
        int index=0;
        while(index<word1.size() || index<word2.size()){
            if (index<word1.size()) {
                ans.push_back(word1[index]);
            }
            if (index<word2.size()) {
                ans.push_back(word2[index]);
            }
            index++;
        }

        return ans;
    }
};