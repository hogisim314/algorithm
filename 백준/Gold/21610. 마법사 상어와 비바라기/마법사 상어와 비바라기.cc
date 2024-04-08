#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int N, M;
int mapp[55][55];
bool cloud[55][55];
vector<pair<int, int> > cloud_info;
int di[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};  // 1베이스
int dj[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};  // 1베이스

int cross_di[] = {0, -1, -1, 1, 1};
int cross_dj[] = {0, -1, 1, 1, -1};

void print_cloud() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << cloud[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void print_mapp() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << mapp[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void get_ans() {
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            ans += mapp[i][j];
        }
    }
    cout << ans << '\n';
    return;
}

void init_cloud() {
    cloud[N][1] = true;
    cloud[N][2] = true;
    cloud[N - 1][1] = true;
    cloud[N - 1][2] = true;
    return;
}

void create_cloud() {
    bool new_cloud[55][55];

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            new_cloud[i][j] = false;
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (!cloud[i][j]) {
                if (mapp[i][j] >= 2) {
                    new_cloud[i][j] = true;
                    mapp[i][j] -= 2;
                }
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cloud[i][j] = new_cloud[i][j];
        }
    }
}

void water_copy_magic() {
    int temp_mapp[55][55];

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            temp_mapp[i][j] = mapp[i][j];
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int cnt = 0;
            if (cloud[i][j]) {
                for (int k = 1; k <= 4; k++) {
                    int ti = i + cross_di[k];
                    int tj = j + cross_dj[k];
                    if (ti < 1 || ti > N || tj < 1 || tj > N) {
                        continue;
                    }
                    if (mapp[ti][tj] > 0) {
                        cnt++;
                    }
                }
                temp_mapp[i][j] += cnt;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            mapp[i][j] = temp_mapp[i][j];
        }
    }
}

void rain() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (cloud[i][j]) {
                mapp[i][j] += 1;
            }
        }
    }
}

void cloud_move(int dir, int speed) {
    bool temp_cloud[55][55];
    int tempi, tempj;
    int new_speed = speed % N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            temp_cloud[i][j] = false;
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (cloud[i][j]) {
                tempi = i + (new_speed * di[dir]);
                tempj = j + (new_speed * dj[dir]);
                if (tempi > N) tempi -= N;
                if (tempj > N) tempj -= N;
                if (tempi < 1) tempi += N;
                if (tempj < 1) tempj += N;
                temp_cloud[tempi][tempj] = true;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cloud[i][j] = temp_cloud[i][j];
        }
    }
    return;
}

void solution() {
    init_cloud();
    for (int i = 1; i <= M; i++) {
        cloud_move(cloud_info[i].first, cloud_info[i].second);
        // print_cloud();
        rain();
        // cout << "after rain mapp" << '\n';
        // print_mapp();
        water_copy_magic();
        // cout << "after water copy" << '\n';
        // print_mapp();
        create_cloud();
        // cout << "after create cloud cloud" << '\n';
        // print_cloud();
        // cout << "after create cloud mapp" << '\n';
        // print_mapp();
    }
    get_ans();
}

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> mapp[i][j];
        }
    }

    cloud_info.push_back({0, 0});  // 임시값

    for (int i = 1; i <= M; i++) {
        int di, si;
        cin >> di >> si;
        cloud_info.push_back({di, si});
    }

    solution();
}