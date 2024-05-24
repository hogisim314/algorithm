class Solution {
public:
    bool isVowel(char c) {
        if (c=='a') {
            return true;
        }
        else if (c=='e') {
            return true;
        }
        else if (c=='i') {
            return true;
        }
        else if (c=='o') {
            return true;
        }
        else if (c=='u') {
            return true;
        }
        return false;
    }
    int maxVowels(string s, int k) {
        //부분합?
        int maxx = 0;
        int cnt=0;
        for (int i=0; i<k; i++) {
            if (isVowel(s[i])) {
                cnt++;
            }
        }
        maxx= max(maxx, cnt);
        int l = 0;
        int r = k-1;
        for (int i=0; i<s.size()-k; i++) {
            if (isVowel(s[i])) {
                cnt--;
            }
            if (isVowel(s[i+k])) {
                cnt++;
            }
            maxx = max(maxx, cnt);
        }
        return maxx;
    }
};