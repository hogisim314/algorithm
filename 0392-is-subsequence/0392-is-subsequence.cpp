class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sIdx=0;
        if (sIdx==s.size()) {
            return true;
        }
        for (int i=0; i<t.size(); i++) {
            if (t[i]==s[sIdx]) {
                sIdx++;
            }
            if (sIdx==s.size()) {
                return true;
            }
        }
        return false;
    }
};