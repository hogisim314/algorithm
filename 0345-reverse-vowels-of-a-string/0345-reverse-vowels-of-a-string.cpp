class Solution {
public:
    bool is_vowel(char c) {
        if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U') {
            return true;
        }
        else return false;
    }

    string reverseVowels(string s) {
        string ans;
        string vowels;
        int index;
        for (int i=0; i<s.size(); i++) {
            if (is_vowel(s[i])) {
                vowels+=s[i];
            }
        }
        index = vowels.size()-1;
        for (int i=0; i<s.size(); i++) {
            if (is_vowel(s[i])) {
                s[i] = vowels[index];
                index--;
            }
        }
        return s;
    }
};