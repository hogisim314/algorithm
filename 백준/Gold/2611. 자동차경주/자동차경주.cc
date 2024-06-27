#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int N, M;
int p, q, r;

int dp[1111];  // dp[n] 은 n으로 올수있는 최대의 거리
int last[1111];
int indegree[1111];  // indegree[i] 는 i로 올수있는 가짓수.
vector<pair<int, int> >
    dist[1111];  // 연결리스트 dist[i]는 i가 갈수있는 위치와 가중치.
int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> p >> q >> r;
        indegree[q]++;
        dist[p].push_back({q, r});
    }

    queue<int> q;
    for (int i = 0; i < dist[1].size(); i++) {
        int dest = dist[1][i].first;
        int weight = dist[1][i].second;
        indegree[dest]--;
        if (indegree[dest] == 0) {
            q.push(dest);
        }

        dp[dest] = weight;
        last[dest] = 1;
    }

    while (q.front() != 1) {
        int src = q.front();
        q.pop();
        for (int i = 0; i < dist[src].size(); i++) {
            int dest = dist[src][i].first;
            int weight = dist[src][i].second;
            indegree[dest]--;
            if (indegree[dest] == 0) {
                q.push(dest);
            }

            if (dp[dest] < dp[src] + weight) {
                dp[dest] = dp[src] + weight;
                last[dest] = src;
            }
        }
    }
    cout << dp[1] << '\n';
    stack<int> s;
    int cur = 1, back;
    s.push(1);
    while (true) {
        cur = last[cur];
        s.push(cur);
        if (cur == 1) {
            break;
        }
    }

    while (!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }
}