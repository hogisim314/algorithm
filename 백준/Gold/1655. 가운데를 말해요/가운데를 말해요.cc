#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> maxpq, minpq;  // maxpq에는 음수붙여서 넣어야함.
void swap_pq() {
    // maxpq랑 minpq랑 top바꾸기
    int a = minpq.top();
    minpq.pop();
    int b = -maxpq.top();
    maxpq.pop();
    minpq.push(b);
    maxpq.push(-a);
}
int n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (i == 0) {
            maxpq.push(-num);
            cout << -maxpq.top() << '\n';
        } else if (i == 1) {
            minpq.push(num);
            if (minpq.top() > -maxpq.top()) {
                swap_pq();
            }
            cout << minpq.top() << '\n';
        } else {
            if (num < minpq.top()) {
                minpq.push(num);
                if (minpq.size() > maxpq.size() + 1) {
                    maxpq.push(-minpq.top());
                    minpq.pop();
                }
            } else if (minpq.top() <= num && num <= -maxpq.top()) {
                minpq.push(num);
                if (minpq.size() > maxpq.size() + 1) {
                    maxpq.push(-minpq.top());
                    minpq.pop();
                }
            } else {
                maxpq.push(-num);
                if (minpq.size() + 1 < maxpq.size()) {
                    minpq.push(-maxpq.top());
                    maxpq.pop();
                }
            }
            if (minpq.size() == maxpq.size()) {
                cout << min(minpq.top(), -maxpq.top()) << '\n';
            } else if (minpq.size() > maxpq.size()) {
                cout << minpq.top() << '\n';
            } else {
                cout << -maxpq.top() << '\n';
            }
        }
    }
}