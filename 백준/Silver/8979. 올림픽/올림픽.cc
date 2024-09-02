#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
int n, k;
int key, g, s, b;
int idx = 1;
bool custom_comp(pair<vector<int>, int> p1, pair<vector<int>, int> p2) {
    vector<int> v1 = p1.first;
    vector<int> v2 = p2.first;

    if (v1[0] > v2[0]) {
        return true;
    } else if (v1[0] == v2[0]) {
        if (v1[1] > v2[1]) {
            return true;
        } else if (v1[1] == v2[1]) {
            if (v1[2] > v2[2]) {
                return true;
            }
        }
    }

    return false;
}

vector<pair<vector<int>, int> > v;

int ranking = 1;

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> key >> g >> s >> b;
        vector<int> temp;
        temp.push_back(g);
        temp.push_back(s);
        temp.push_back(b);
        v.push_back(make_pair(temp, key));
    }

    sort(v.begin(), v.end(), custom_comp);
    if (v[0].second == k) {
        cout << 1;
        return 0;
    }
    for (int i = 1; i < v.size(); i++) {
        if (v[i].first == v[i - 1].first) {
        } else {
            ranking = i + 1;
        }
        if (v[i].second == k) {
            cout << ranking << '\n';
            return 0;
        }
    }
}