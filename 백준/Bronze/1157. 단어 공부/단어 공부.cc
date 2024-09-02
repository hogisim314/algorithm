#include <algorithm>
#include <iostream>
#include <map>
#include <string>
using namespace std;
string str;
map<char, int> m;
int MAX;
bool same;
char ans;
int main() {
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        if ('A' <= str[i] && str[i] <= 'Z') {
            m[str[i] - ('A' - 'a')]++;
        } else
            m[str[i]]++;
    }

    for (int i = 0; i < 26; i++) {
        int value = m[i + 'a'];
        if (value > MAX) {
            ans = i + 'A';
            MAX = value;
            same = false;
        } else if (value == MAX) {
            same = true;
        }
    }

    if (same) {
        cout << "?";
    } else
        cout << ans;
}