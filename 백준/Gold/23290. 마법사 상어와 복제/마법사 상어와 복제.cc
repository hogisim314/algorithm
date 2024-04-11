#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
int M, S;
int fx, fy, dir;
int sx, sy;
int fish_smell[5][5];
int mapp[5][5];
int di[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int dj[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int sdi[] = {0, -1, 0, 1, 0};
int sdj[] = {0, 0, -1, 0, 1};
int parr[4];
int ans;

class Fish {
   public:
    int r;
    int c;
    int d;
    int live;
    int temp_live;
    Fish(int r, int c, int d) {
        this->r = r;
        this->c = c;
        this->d = d;
        this->live = 1;
        this->temp_live = 1;
    }
};

vector<Fish> fishList;
vector<vector<int> > orderList;
vector<Fish> copyList;
void print_fish_info() {
    for (auto fish : fishList) {
        if (fish.live) {
            cout << fish.r << ' ' << fish.c << ' ' << fish.d << '\n';
        }
    }
    cout << '\n';
}
void print_smell() {
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            cout << fish_smell[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void permu(int depth) {
    if (depth == 4) {
        vector<int> temp;
        for (int i = 1; i <= 3; i++) {
            temp.push_back(parr[i]);
        }
        orderList.push_back(temp);
        return;
    }
    for (int i = 1; i <= 4; i++) {
        parr[depth] = i;
        permu(depth + 1);
    }
}

void input() {
    cin >> M >> S;
    for (int i = 1; i <= M; i++) {
        cin >> fx >> fy >> dir;
        Fish fish = Fish(fx, fy, dir);
        fishList.push_back(fish);
    }
    cin >> sx >> sy;
}

bool is_ok_for_fish(int i, int j) {
    if (i < 1 || i > 4 || j < 1 || j > 4 || (i == sx && j == sy) ||
        fish_smell[i][j] > 0)
        return false;
    return true;
}

bool is_ok_for_shark(int i, int j) {
    if (i < 1 || i > 4 || j < 1 || j > 4) return false;
    return true;
}

void fish_move() {
    for (int i = 0; i < fishList.size(); i++) {
        Fish& fish = fishList[i];
        int curi = fish.r;
        int curj = fish.c;
        int dir = fish.d;
        int initDir = dir;
        while (true) {
            int ti = curi + di[dir];
            int tj = curj + dj[dir];
            if (is_ok_for_fish(ti, tj)) {
                fish.r = ti;
                fish.c = tj;
                fish.d = dir;
                break;
            } else {
                dir--;
                if (dir == 0) {
                    dir = 8;
                }
                if (dir == initDir) {
                    break;
                }
            }
        }
    }
}

void shark_move() {
    int dir;
    int maxx = -1;
    int minindex = 65;
    for (int i = 0; i < orderList.size(); i++) {
        int sum = 0;
        int row = sx;
        int col = sy;
        bool impossible = false;
        for (int j = 0; j < 3; j++) {
            dir = orderList[i][j];
            int ti = row + sdi[dir];
            int tj = col + sdj[dir];
            if (is_ok_for_shark(ti, tj)) {
                for (int k = 0; k < fishList.size(); k++) {
                    if (fishList[k].r == ti && fishList[k].c == tj &&
                        fishList[k].live && fishList[k].temp_live) {
                        sum++;
                        fishList[k].temp_live = 0;
                    }
                }
                row = ti;
                col = tj;
            } else {
                impossible = true;
                sum = 0;
                break;
            }
        }
        // cout << orderList[i][0] << ' ' << orderList[i][1] << ' '
        //      << orderList[i][2] << ' ' << sum << '\n';
        for (int k = 0; k < fishList.size(); k++) {
            if (fishList[k].live) {
                fishList[k].temp_live = 1;
            }
        }
        if (!impossible) {  // 3칸 다 움직인 경우
            if (maxx < sum) {
                maxx = sum;
                minindex = i;
            } else if (maxx == sum) {
                if (minindex > i) {
                    minindex = i;
                }
            }
        }
    }
    // cout << "sharkMoved" << '\n';
    if (minindex > 64) {
        cout << "64 seg fault" << '\n';
        return;
    }

    // 이제 minindex대로 움직여 줘야함.
    // cout << "이동방향 " << orderList[minindex][0] << ' '
    //      << orderList[minindex][1] << ' ' << orderList[minindex][2] << '\n';
    for (int i = 0; i < 3; i++) {
        dir = orderList[minindex][i];
        sx = sx + sdi[dir];
        sy = sy + sdj[dir];
        for (int k = 0; k < fishList.size(); k++) {
            if (fishList[k].r == sx && fishList[k].c == sy &&
                fishList[k].live && fishList[k].temp_live) {
                // 격자에서 제외
                fishList[k].live = 0;
                fishList[k].temp_live = 0;
                // 물고기냄새 남기기
                fish_smell[sx][sy] = 3;
            }
        }
    }
}

void remove_smell() {
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            fish_smell[i][j] =
                fish_smell[i][j] ? fish_smell[i][j] - 1 : fish_smell[i][j];
        }
    }
}

void copy_fish_generate() {
    for (int i = 0; i < copyList.size(); i++) {
        fishList.push_back(copyList[i]);
    }
}

void copy_fish() {
    copyList.clear();
    for (int i = 0; i < fishList.size(); i++) {
        if (fishList[i].live) {
            Fish copiedFish = Fish(fishList[i].r, fishList[i].c, fishList[i].d);
            copyList.push_back(copiedFish);
        }
    }
}

void solution() {
    permu(1);
    for (int i = 1; i <= S; i++) {
        copy_fish();
        // print_fish_info();
        fish_move();
        // print_fish_info();
        shark_move();
        remove_smell();
        // print_smell();
        copy_fish_generate();
        // print_fish_info();
    }
    for (int i = 0; i < fishList.size(); i++) {
        if (fishList[i].live) {
            ans++;
        }
    }
    cout << ans;
    return;
}

int main() {
    input();
    solution();
}