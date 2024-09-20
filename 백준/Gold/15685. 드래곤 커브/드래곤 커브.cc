#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n;
int x, y, d, g;
bool arr[111][111];
int cnt;
class dragon_curve {
   public:
    int i;
    int j;
    int dir;
    int gen;
    vector<pair<pair<int, int>, int> > v;

    dragon_curve() {}
    dragon_curve(int i, int j, int dir, int gen) {
        this->i = i;
        this->j = j;
        this->dir = dir;
        this->gen = gen;
        v.emplace_back(make_pair(make_pair(i, j), dir));
    }

    void rotate() {
        int ri = v.back().first.first;
        int rj = v.back().first.second;
        vector<int> newDir;
        int vsz = v.size();
        for (int i = vsz - 1; i >= 0; --i) {
            int cd = v[i].second;
            int nd = (cd + 1) % 4;
            newDir.push_back(nd);
        }
        for (int i = 0; i < newDir.size(); ++i) {
            if (newDir[i] == 0) {
                arr[ri][rj] = true;
                arr[ri][rj + 1] = true;
                ri = ri;
                rj = rj + 1;
                v.push_back(make_pair(make_pair(ri, rj), newDir[i]));
            } else if (newDir[i] == 1) {
                arr[ri][rj] = true;
                arr[ri - 1][rj] = true;
                ri = ri - 1;
                rj = rj;
                v.push_back(make_pair(make_pair(ri, rj), newDir[i]));
            } else if (newDir[i] == 2) {
                arr[ri][rj] = true;
                arr[ri][rj - 1] = true;
                ri = ri;
                rj = rj - 1;
                v.push_back(make_pair(make_pair(ri, rj), newDir[i]));
            } else if (newDir[i] == 3) {
                arr[ri][rj] = true;
                arr[ri + 1][rj] = true;
                ri = ri + 1;
                rj = rj;
                v.push_back(make_pair(make_pair(ri, rj), newDir[i]));
            }
        }
    }
};

vector<dragon_curve> curves;

int main() {
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> x >> y >> d >> g;
        arr[y][x] = true;
        if (d == 0) {
            arr[y][x + 1] = true;
            curves.push_back(dragon_curve(y, x + 1, d, g));
        } else if (d == 1) {
            arr[y - 1][x] = true;
            curves.push_back(dragon_curve(y - 1, x, d, g));
        } else if (d == 2) {
            arr[y][x - 1] = true;
            curves.push_back(dragon_curve(y, x - 1, d, g));
        } else if (d == 3) {
            arr[y + 1][x] = true;
            curves.push_back(dragon_curve(y + 1, x, d, g));
        }
    }

    for (int i = 0; i < curves.size(); ++i) {
        dragon_curve dc = curves[i];
        for (int r = 0; r < dc.gen; r++) {
            dc.rotate();
        }
    }

    for (int i = 0; i <= 100; ++i) {
        for (int j = 0; j <= 100; ++j) {
            if (arr[i][j] && arr[i + 1][j] && arr[i][j + 1] &&
                arr[i + 1][j + 1]) {
                cnt++;
            }
        }
    }

    cout << cnt;
}
