class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size()!=word2.size()) {
            return false;
        }
        else {
            set<char> s1, s2;
            map<char, int> m1, m2;
            map<int, int> cnt1,cnt2;
            for (int i=0; i<word1.size(); i++) {
                s1.insert(word1[i]);
                m1[word1[i]]++;
            }

            for (int i=0; i<word2.size(); i++) {
                s2.insert(word2[i]);
                m2[word2[i]]++;
            }

            for (auto itr=m1.begin(); itr!=m1.end(); itr++) {
                cnt1[itr->second]++;
            }

            for (auto itr=m2.begin(); itr!=m2.end(); itr++) {
                cnt2[itr->second]++;
            }

            for (auto itr = s1.begin(); itr!=s1.end(); itr++) {
                if (s2.find(*itr)==s2.end()) {
                    return false;
                }
            }
            
            for (auto itr = s2.begin(); itr!=s2.end(); itr++) {
                if (s1.find(*itr)==s1.end()) {
                    return false;
                }
            }

            for (auto itr = cnt1.begin(); itr!=cnt1.end(); itr++) {
                if (cnt2[itr->first]!=itr->second) {
                    return false;
                }
            }

            for (auto itr = cnt2.begin(); itr!=cnt2.end(); itr++) {
                if (cnt1[itr->first]!=itr->second) {
                    return false;
                }
            }
        }
        return true;
    }
};