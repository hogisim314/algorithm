#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int R, C, K, W;
int x, y, t;
int arr[22][22];
int temperature[22][22];
int chocolate = 0;

int di[] = {0, 0, 0, -1, 1};
int dj[] = {0, 1, -1, 0, 0};

vector<vector<int> > hitter;   // i,j,방향 로 저장
vector<vector<int> > inspect;  // i,j 로 저장
vector<vector<int> > wall_info;

void eat() { chocolate++; }

bool is_wall(int i1, int j1, int i2, int j2) {
    for (int i = 1; i < wall_info.size(); i++) {
        if (i1 == wall_info[i][0] && j1 == wall_info[i][1]) {
            if (i2 == wall_info[i][2] && j2 == wall_info[i][3]) {
                return true;
            }
        } else if (i1 == wall_info[i][2] && j1 == wall_info[i][3]) {
            if (i2 == wall_info[i][0] && j2 == wall_info[i][1]) {
                return true;
            }
        }
    }
    return false;
}

void print_temperature() {
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cout << temperature[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

bool is_outside(int i, int j) {
    if (i < 1 || i > R || j < 1 || j > C) return true;
    return false;
}

void control_temp() {
    int temp[22][22];
    int diff = 0;
    int delta = 0;

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            temp[i][j] = 0;
        }
    }

    // 먼저 세로 볼거임
    for (int j = 1; j <= C; j++) {
        for (int i = 1; i <= R - 1; i++) {
            // i,j랑 i+1,j랑
            if (temperature[i][j] > temperature[i + 1][j] &&
                !is_wall(i, j, i + 1, j)) {
                diff = temperature[i][j] - temperature[i + 1][j];
                delta = diff / 4;
                temp[i][j] -= delta;
                temp[i + 1][j] += delta;
            } else if (temperature[i][j] < temperature[i + 1][j] &&
                       !is_wall(i, j, i + 1, j)) {
                diff = temperature[i + 1][j] - temperature[i][j];
                delta = diff / 4;
                temp[i][j] += delta;
                temp[i + 1][j] -= delta;
            }
        }
    }

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C - 1; j++) {
            // i,j랑 i,j+1랑
            if (temperature[i][j] > temperature[i][j + 1] &&
                !is_wall(i, j, i, j + 1)) {
                diff = temperature[i][j] - temperature[i][j + 1];
                delta = diff / 4;
                temp[i][j] -= delta;
                temp[i][j + 1] += delta;
            } else if (temperature[i][j] < temperature[i][j + 1] &&
                       !is_wall(i, j, i, j + 1)) {
                diff = temperature[i][j + 1] - temperature[i][j];
                delta = diff / 4;
                temp[i][j] += delta;
                temp[i][j + 1] -= delta;
            }
        }
    }

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            temperature[i][j] += temp[i][j];
        }
    }
}

void outer_control() {
    for (int i = 1; i <= R; i++) {
        if (temperature[i][1] >= 1) {
            temperature[i][1]--;
        }
        if (temperature[i][C] >= 1) {
            temperature[i][C]--;
        }
    }
    for (int j = 2; j <= C - 1; j++) {
        if (temperature[1][j] >= 1) {
            temperature[1][j]--;
        }
        if (temperature[R][j] >= 1) {
            temperature[R][j]--;
        }
    }
}

void wind_blow() {
    int row, col, dir;
    for (int i = 1; i < hitter.size(); i++) {
        int temp[22][22];
        vector<pair<int, int> > before;
        vector<pair<int, int> > after;
        for (int r = 1; r <= R; r++) {
            for (int c = 1; c <= C; c++) {
                temp[r][c] = 0;
            }
        }

        int wind = 5;
        int cnt = 1;
        row = hitter[i][0];
        col = hitter[i][1];
        dir = hitter[i][2];
        while (wind) {
            if (wind == 5) {  // 벽 하나만 보면 됨.
                // 벽이 사이에 있거나 맵 밖이면 그만하면 됨.
                if (is_outside(row + di[dir], col + dj[dir])) {
                    break;
                } else {
                    temp[row + di[dir]][col + dj[dir]] = wind;
                    after.push_back(make_pair(row + di[dir], col + dj[dir]));
                }
            } else {
                before.clear();
                for (int j = 0; j < after.size(); j++) {
                    before.push_back(
                        make_pair(after[j].first, after[j].second));
                }
                after.clear();
                for (int k = 0; k < before.size(); k++) {
                    row = before[k].first;
                    col = before[k].second;
                    if (dir == 1) {
                        if (!is_outside(row - 1, col + 1) &&
                            !is_wall(row, col, row - 1, col) &&
                            !is_wall(row - 1, col, row - 1, col + 1)) {
                            if (!temp[row - 1][col + 1]) {
                                after.push_back(make_pair(row - 1, col + 1));
                            }
                            temp[row - 1][col + 1] = wind;
                        }
                        if (!is_outside(row, col + 1) &&
                            !is_wall(row, col, row, col + 1)) {
                            if (!temp[row][col + 1]) {
                                after.push_back(make_pair(row, col + 1));
                            }
                            temp[row][col + 1] = wind;
                        }
                        if (!is_outside(row + 1, col + 1) &&
                            !is_wall(row, col, row + 1, col) &&
                            !is_wall(row + 1, col, row + 1, col + 1)) {
                            if (!temp[row + 1][col + 1]) {
                                after.push_back(make_pair(row + 1, col + 1));
                            }
                            temp[row + 1][col + 1] = wind;
                        }
                    } else if (dir == 2) {
                        if (!is_outside(row - 1, col - 1) &&
                            !is_wall(row, col, row - 1, col) &&
                            !is_wall(row - 1, col, row - 1, col - 1)) {
                            if (!temp[row - 1][col - 1]) {
                                after.push_back(make_pair(row - 1, col - 1));
                            }
                            temp[row - 1][col - 1] = wind;
                        }
                        if (!is_outside(row, col - 1) &&
                            !is_wall(row, col, row, col - 1)) {
                            if (!temp[row][col - 1]) {
                                after.push_back(make_pair(row, col - 1));
                            }
                            temp[row][col - 1] = wind;
                        }
                        if (!is_outside(row + 1, col - 1) &&
                            !is_wall(row, col, row + 1, col) &&
                            !is_wall(row + 1, col, row + 1, col - 1)) {
                            if (!temp[row + 1][col - 1]) {
                                after.push_back(make_pair(row + 1, col - 1));
                            }
                            temp[row + 1][col - 1] = wind;
                        }
                    } else if (dir == 3) {
                        if (!is_outside(row - 1, col - 1) &&
                            !is_wall(row, col, row, col - 1) &&
                            !is_wall(row, col - 1, row - 1, col - 1)) {
                            if (!temp[row - 1][col - 1]) {
                                after.push_back(make_pair(row - 1, col - 1));
                            }
                            temp[row - 1][col - 1] = wind;
                        }
                        if (!is_outside(row - 1, col) &&
                            !is_wall(row, col, row - 1, col)) {
                            if (!temp[row - 1][col]) {
                                after.push_back(make_pair(row - 1, col));
                            }
                            temp[row - 1][col] = wind;
                        }
                        if (!is_outside(row - 1, col + 1) &&
                            !is_wall(row, col, row, col + 1) &&
                            !is_wall(row, col + 1, row - 1, col + 1)) {
                            if (!temp[row - 1][col + 1]) {
                                after.push_back(make_pair(row - 1, col + 1));
                            }
                            temp[row - 1][col + 1] = wind;
                        }
                    } else if (dir == 4) {
                        if (wind == 3) {
                        }
                        if (!is_outside(row + 1, col - 1) &&
                            !is_wall(row, col, row, col - 1) &&
                            !is_wall(row, col - 1, row + 1, col - 1)) {
                            if (!temp[row + 1][col - 1]) {
                                after.push_back(make_pair(row + 1, col - 1));
                            }
                            temp[row + 1][col - 1] = wind;
                        }
                        if (!is_outside(row + 1, col) &&
                            !is_wall(row, col, row + 1, col)) {
                            if (!temp[row + 1][col]) {
                                after.push_back(make_pair(row + 1, col));
                            }
                            temp[row + 1][col] = wind;
                        }
                        if (!is_outside(row + 1, col + 1) &&
                            !is_wall(row, col, row, col + 1) &&
                            !is_wall(row, col + 1, row + 1, col + 1)) {
                            if (!temp[row + 1][col + 1]) {
                                after.push_back(make_pair(row + 1, col + 1));
                            }
                            temp[row + 1][col + 1] = wind;
                        }
                    }
                }
            }
            wind--;
            cnt += 2;
        }

        for (int r = 1; r <= R; r++) {
            for (int c = 1; c <= C; c++) {
                temperature[r][c] += temp[r][c];
            }
        }
    }
}

void Input() {
    cin >> R >> C >> K;
    hitter.push_back({0});
    inspect.push_back({0});
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> arr[i][j];
            if (arr[i][j] >= 1 && arr[i][j] <= 4) {
                hitter.push_back({i, j, arr[i][j]});
            } else if (arr[i][j] == 5) {
                inspect.push_back({i, j});
            }
        }
    }
    cin >> W;
    wall_info.push_back({0});
    for (int i = 1; i <= W; i++) {
        cin >> x >> y >> t;
        if (t == 0) {
            wall_info.push_back({x, y, x - 1, y});
        } else if (t == 1) {
            wall_info.push_back({x, y, x, y + 1});
        }
    }
}

bool finish_check() {
    bool flag = true;
    for (int i = 1; i < inspect.size(); i++) {
        if (temperature[inspect[i][0]][inspect[i][1]] < K) {
            flag = false;
            return flag;
        }
    }
    return flag;
}

void solution() {
    while (true) {
        wind_blow();
        // print_temperature();
        control_temp();
        outer_control();
        // print_temperature();

        eat();
        if (finish_check() || chocolate > 100) {
            break;
        }
    }
    if (chocolate > 100) {
        chocolate = 101;
    }
    cout << chocolate;
    return;
}

int main() {
    Input();
    solution();
}