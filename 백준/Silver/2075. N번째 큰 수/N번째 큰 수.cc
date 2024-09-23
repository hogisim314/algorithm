#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
priority_queue<int> pq;
int n;
int num;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n * n; ++i) {
        cin >> num;
        pq.push(-num);
        if (pq.size() > n) pq.pop();
    }
    cout << -pq.top();
}