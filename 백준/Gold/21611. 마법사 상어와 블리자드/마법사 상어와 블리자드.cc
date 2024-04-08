#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N, M;
int di[] = {0, -1, 1, 0, 0};  // 1베이스
int dj[] = {0, 0, 0, -1, 1};
int init_di[] = {0, 0, 1, 0, -1};
int init_dj[] = {0, -1, 0, 1, 0};
int mapp[55][55];
int marble[4];  // 0은 그냥 채우기 1 2 3
int sharki, sharkj;
vector<pair<int, int> > magic_info;  // 1베이스
vector<pair<int, int> > order;

void print_mapp() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << mapp[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void grouping() {
    vector<pair<int, int> > info;  // 갯수 번호
    int color;
    int index;
    int cnt;
    for (int i = 0; i < order.size(); i++) {
        color = mapp[order[i].first][order[i].second];
        if (color == 0) {
            break;
        }
        index = i;
        cnt = 1;
        while (index < order.size() &&
               color == mapp[order[index + 1].first][order[index + 1].second]) {
            index++;
            cnt++;
        }
        i = index;
        info.push_back(make_pair(cnt, color));
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            mapp[i][j] = 0;  // 초기화
        }
    }
    int orderIdx = 0;
    for (int i = 0; i < info.size(); i++) {
        mapp[order[orderIdx].first][order[orderIdx].second] = info[i].first;
        orderIdx++;
        if (orderIdx > order.size() - 1) break;
        mapp[order[orderIdx].first][order[orderIdx].second] = info[i].second;
        orderIdx++;
        if (orderIdx > order.size() - 1) break;
    }
}

int bomb() {  // 여기 코드 어떻게 짜는지 보기
    int bombcnt = 0;
    int color;
    int index;
    int cnt = 0;
    for (int i = 0; i < order.size() - 3; i++) {
        index = i;
        cnt = 1;
        color = mapp[order[i].first][order[i].second];
        if (color == 0) continue;
        while (index + 1 < order.size() - 1 &&
               color == mapp[order[index + 1].first][order[index + 1].second]) {
            index++;
            cnt++;
        }
        // cout << order[i].first << ' ' << order[i].second << ' ' << cnt <<
        // '\n';
        if (cnt >= 4) {
            for (int j = i; j <= index; j++) {
                mapp[order[j].first][order[j].second] = 0;
            }
            bombcnt += (index - i + 1);
            marble[color] += (index - i + 1);
            i = index;
        } else
            continue;
    }
    return bombcnt;
}

void remove_empty() {
    int curi, curj;
    int tempi, tempj;
    int index;
    for (int i = 0; i < order.size(); i++) {
        curi = order[i].first;
        curj = order[i].second;
        index = i;
        bool flag = false;
        if (mapp[curi][curj])
            continue;
        else {  // 공백 발견
            while (true) {
                if (index >= order.size() - 1) {
                    break;
                }
                index++;  // 다음꺼 확인
                tempi = order[index].first;
                tempj = order[index].second;
                if (mapp[tempi][tempj] == 0) {  // 다음것도 공백이라면 또 넘어감
                    continue;
                } else if (mapp[tempi][tempj] > 0) {  // 공백 아닌거 발견
                    flag = true;
                    break;
                }
            }
            if (!flag) {  // 마지막 까지 왔다면 그냥 넘어가야함
                continue;
            } else if (flag) {
                mapp[curi][curj] = mapp[tempi][tempj];
                mapp[tempi][tempj] = 0;
            }
        }
    }
}

void throw_marble(int dir, int speed) {
    int ti = sharki + (di[dir] * speed);
    int tj = sharkj + (dj[dir] * speed);

    if (ti > sharki && tj == sharkj) {
        for (int i = sharki + 1; i <= ti; i++) {
            mapp[i][tj] = 0;
        }
    } else if (ti < sharki && tj == sharkj) {
        for (int i = ti; i <= sharki; i++) {
            mapp[i][tj] = 0;
        }
    } else if (ti == sharki && tj > sharkj) {
        for (int j = sharkj; j <= tj; j++) {
            mapp[sharki][j] = 0;
        }
    } else if (ti == sharki && tj < sharkj) {
        for (int j = tj; j <= sharkj; j++) {
            mapp[sharki][j] = 0;
        }
    }
}

void Input() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> mapp[i][j];
        }
    }
    magic_info.push_back(make_pair(0, 0));  // 1베이스 맞출려고
    for (int i = 1; i <= M; i++) {
        int di, si;
        cin >> di >> si;
        magic_info.push_back(make_pair(di, si));
    }
}

void solution() {
    for (int i = 1; i <= M; i++) {
        throw_marble(magic_info[i].first, magic_info[i].second);
        while (true) {
            remove_empty();
            int bombcnt = bomb();
            if (bombcnt == 0) {
                break;
            }
        }
        grouping();
    }
    cout << (1 * marble[1]) + (2 * marble[2]) + (3 * marble[3]);
}

void init() {
    sharki = (N + 1) / 2;
    sharkj = (N + 1) / 2;
    int curi = sharki;
    int curj = sharkj;
    int dist = 1;
    int dir = 1;
    int cnt = 0;
    while (true) {
        if (curi == 1) {
            dist--;
            for (int k = 1; k <= dist; k++) {
                order.push_back(make_pair(curi + (init_di[dir] * k),
                                          curj + (init_dj[dir] * k)));
            }
            break;
        }
        for (int k = 1; k <= dist; k++) {
            order.push_back(make_pair(curi + (init_di[dir] * k),
                                      curj + (init_dj[dir] * k)));
        }
        curi = curi + (init_di[dir] * dist);
        curj = curj + (init_dj[dir] * dist);

        dir++;
        if (dir > 4) {
            dir = 1;
        }
        cnt++;

        if (cnt == 2) {
            dist++;
            cnt = 0;
        }
    }
}

int main() {
    Input();
    init();
    solution();
}