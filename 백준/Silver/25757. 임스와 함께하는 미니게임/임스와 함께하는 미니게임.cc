#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <string>
using namespace std;
set<string> s;
queue<string> q;
int n;
char c;
int gameCnt;
string name;
int globalCnt;
int main() {
    cin >> n >> c;
    if (c == 'Y') gameCnt = 1;
    if (c == 'F') gameCnt = 2;
    if (c == 'O') gameCnt = 3;
    for (int i = 1; i <= n; i++) {
        cin >> name;
        if (s.find(name) != s.end()) continue;
        q.push(name);
        if (q.size() == gameCnt) {
            globalCnt++;
            while (!q.empty()) {
                s.insert(q.front());
                q.pop();
            }
        }
    }
    cout << globalCnt;
}