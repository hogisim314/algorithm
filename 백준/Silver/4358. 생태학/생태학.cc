#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

map<string, int> dict;
int total;
string tree;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while (getline(cin, tree)) {
        total++;
        dict[tree]++;
    }
    cout << fixed;
    cout.precision(4);
    for (auto itr = dict.begin(); itr != dict.end(); itr++) {
        cout << itr->first << ' ' << float(itr->second) * 100 / total << '\n';
    }
}