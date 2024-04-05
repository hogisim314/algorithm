#include <memory.h>

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int di[] = {-1, 0, 1, 0};
int dj[] = {0, 1, 0, -1};
int n, m, fuel;
int currow, curcol;
int mapp[22][22];
int dist[22][22];  // 거리가 양수라면 갔다왔다는 소리임.
vector<vector<int> > customer;
bool finished[404];
int a, b, c, d;
// 거리가 같은 손님이면 행, 열 순서로 가장 작은 손님 태워야함
// 지금까지의 거리 / 손님 번호 / 행 / 열
bool customer_cmp(vector<int> v1, vector<int> v2) {
    if (v1[0] < v2[0]) {  // 거리가 작다면 트루
        return true;
    } else if (v1[0] == v2[0]) {  // 거리가 같다면
        if (v1[2] < v2[2]) {      // 행이 작은애를 리턴
            return true;
        } else if (v1[2] == v2[2]) {  // 행도 같다면
            if (v1[3] < v2[3]) {      // 열이 작은 애를 트루
                return true;
            } else
                return false;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

bool is_ok(int i, int j) {
    if (i < 1 || i > n || j < 1 || j > n || dist[i][j] || mapp[i][j] == 1) {
        return false;
    }
    return true;
}

int is_customer(int i, int j) {
    for (int cust = 1; cust <= m; cust++) {
        if (i == customer[cust][1] && j == customer[cust][2] &&
            !finished[cust]) {  // 완료가 안된 손님
            return cust;
        }
    }
    return 0;
}

bool is_all_pickup() {
    for (int i = 1; i <= m; i++) {
        if (finished[i] == false) {
            return false;
        }
    }
    return true;
}

void print() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

int bfs_cust() {
    queue<pair<int, int> > q;
    vector<vector<int> > candidateCustomer;
    int custNum = 0;
    int distance = 0;
    int candi = 30;
    int candj = 30;
    memset(dist, 0, sizeof(dist));
    if ((custNum = is_customer(currow, curcol))) {
        finished[custNum] = 1;
        return custNum;
    }
    q.push(make_pair(currow, curcol));
    dist[currow][curcol] = 1;
    while (!q.empty()) {
        int curi = q.front().first;
        int curj = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int ti = curi + di[k];
            int tj = curj + dj[k];
            if (is_ok(ti, tj)) {
                dist[ti][tj] = dist[curi][curj] + 1;
                if ((custNum = is_customer(ti, tj))) {
                    vector<int> temp;  // 지금까지의 거리 / 손님 번호 / 행 / 열
                    temp.push_back(dist[ti][tj] - 1);
                    temp.push_back(custNum);
                    temp.push_back(ti);
                    temp.push_back(tj);
                    candidateCustomer.push_back(temp);
                } else {  // 손님이 아니라면
                    q.push(make_pair(ti, tj));
                }
            }
        }
    }
    if (candidateCustomer.empty()) {
        return -1;
    }
    sort(candidateCustomer.begin(), candidateCustomer.end(), customer_cmp);

    distance = candidateCustomer[0][0];
    custNum = candidateCustomer[0][1];
    currow = candidateCustomer[0][2];
    curcol = candidateCustomer[0][3];
    finished[custNum] = true;
    fuel -= distance;
    if (fuel > 0) {
        return custNum;
    } else if (fuel <= 0) {
        return -1;
    }
}

int bfs_dest(int custNum) {
    queue<pair<int, int> > q;
    q.push({currow, curcol});
    memset(dist, 0, sizeof(dist));
    dist[currow][curcol] = 1;
    int desti = customer[custNum][3];
    int destj = customer[custNum][4];
    bool found = false;
    int distance = 0;
    while (!q.empty()) {
        int curi = q.front().first;
        int curj = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++) {
            int ti = curi + di[k];
            int tj = curj + dj[k];

            if (is_ok(ti, tj)) {
                dist[ti][tj] = dist[curi][curj] + 1;
                if (ti == desti && tj == destj) {
                    currow = desti;
                    curcol = destj;
                    found = true;
                    distance = dist[ti][tj] - 1;
                    break;
                } else {
                    q.push(make_pair(ti, tj));
                }
            }
        }
        if (found) {
            break;
        }
    }
    if (!found) {
        return -1;
    }
    fuel -= distance;
    if (fuel >= 0) {
        fuel += (2 * distance);
        return fuel;
    } else if (fuel < 0) {
        return -1;
    }
}

int main() {
    cin >> n >> m >> fuel;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> mapp[i][j];
        }
    }
    cin >> currow >> curcol;
    vector<int> tmp;
    tmp.push_back(0);
    customer.push_back(tmp);
    for (int i = 1; i <= m; i++) {
        vector<int> v;
        cin >> a >> b >> c >> d;
        v.push_back(0);
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        v.push_back(d);
        customer.push_back(v);
    }
    while (true) {
        if (is_all_pickup()) {
            cout << fuel;
            break;
        }
        int custNum = bfs_cust();
        if (custNum == -1) {
            cout << -1;
            break;
        }
        if (bfs_dest(custNum) == -1) {
            cout << -1;
            break;
        }
    }
    return 0;
}