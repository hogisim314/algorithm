class Solution {
public:
    set<char> vowel;
    int cnt=0;
    int ans=0;
    int maxVowels(string s, int k) {
        vowel.insert('a');
        vowel.insert('e');
        vowel.insert('i');
        vowel.insert('o');
        vowel.insert('u');
        for (int i=0; i<k; i++) {
            if (vowel.contains(s[i])) {
                cnt++;
            }
        }
        ans = max(ans, cnt);
        for (int i=0; i<s.size()-k; i++) {
            if (vowel.contains(s[i])) {
                cnt--;
            }
            if (vowel.contains(s[i+k])) {
                cnt++;
            }
            ans = max(ans,cnt);
        }
        return ans;
    }
};