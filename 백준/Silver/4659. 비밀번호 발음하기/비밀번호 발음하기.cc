#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string s;

bool is_vowel(char c) {
    if (c == 'a') {
        return true;
    } else if (c == 'e') {
        return true;
    } else if (c == 'i') {
        return true;
    } else if (c == 'o') {
        return true;
    } else if (c == 'u') {
        return true;
    } else
        return false;
}
int main() {
    while (true) {
        cin >> s;
        int sz = s.size();
        if (s == "end") break;
        bool flag1 = false, flag2 = true, flag3 = true;
        for (int i = 0; i < sz; i++) {
            if (is_vowel(s[i])) {
                flag1 = true;
                break;
            }
        }
        if (!flag1) {
            cout << "<" << s << "> is not acceptable." << '\n';
            continue;
        }
        for (int i = 0; i < (sz - 2); i++) {
            if (is_vowel(s[i]) && is_vowel(s[i + 1]) && is_vowel(s[i + 2])) {
                flag2 = false;
                break;
            }
            if (!is_vowel(s[i]) && !is_vowel(s[i + 1]) && !is_vowel(s[i + 2])) {
                flag2 = false;
                break;
            }
        }
        if (!flag2) {
            cout << "<" << s << "> is not acceptable." << '\n';
            continue;
        }
        for (int i = 0; i < sz - 1; i++) {
            if (s[i] == s[i + 1]) {
                if ((s[i] == 'e' && s[i + 1] == 'e') ||
                    (s[i] == 'o' && s[i + 1] == 'o')) {
                    continue;
                } else {
                    flag3 = false;
                    break;
                }
            }
        }
        if (!flag3) {
            cout << "<" << s << "> is not acceptable." << '\n';
            continue;
        }

        cout << "<" << s << "> is acceptable." << '\n';
    }
}