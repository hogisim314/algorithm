#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
int w, h, num;
int dir, pos;
int d_dir, d_pos;
vector<pair<int, int> > locs;
int ans;
void foo() {
    for (int i = 0; i < locs.size(); i++) {
        dir = locs[i].first;
        pos = locs[i].second;

        if (dir == d_dir) {  // 1,1 2,2 3,3 4,4
            ans += abs(pos - d_pos);
        } else if (dir <= 2 && d_dir <= 2) {  // 1,2 2,1
            ans += h;
            ans += min(d_pos + pos, w - d_pos + w - pos);
        } else if (3 <= dir && dir <= 4 && 3 <= d_dir &&
                   d_dir <= 4) {  // 3,4 4,3
            ans += w;
            ans += min(d_pos + pos, h - d_pos + h - pos);
        } else if ((dir == 1 && d_dir == 3) || (dir == 3 && d_dir == 1)) {
            ans += d_pos + pos;
        } else if ((dir == 1 && d_dir == 4) || (dir == 4 && d_dir == 1)) {
            if (dir == 1) {
                ans += w - pos;
                ans += d_pos;
            } else if (dir == 4) {
                ans += w - d_pos;
                ans += pos;
            }
        } else if ((dir == 2 && d_dir == 3) || (dir == 3 && d_dir == 2)) {
            if (dir == 2) {
                ans += pos;
                ans += h - d_pos;
            } else if (dir == 3) {
                ans += d_pos;
                ans += h - pos;
            }
        } else if ((dir == 2 && d_dir == 4) || (dir == 4 && d_dir == 2)) {
            ans += w - pos;
            ans += h - d_pos;
        }
        // cout << ans << '\n';
    }
}

int main() {
    cin >> w >> h >> num;
    for (int i = 1; i <= num; i++) {
        cin >> dir >> pos;
        locs.push_back(make_pair(dir, pos));
    }
    cin >> d_dir >> d_pos;

    foo();
    cout << ans;
}