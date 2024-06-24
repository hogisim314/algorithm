#include <deque>
#include <iostream>
#include <string>
using namespace std;
int num[111];
deque<int> dq;
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        if (num[i] == 0) {
            dq.push_back(i + 1);
        } else {
            dq.insert(dq.end() - num[i], i + 1);
        }
    }
    for (int i = 0; i < dq.size(); i++) {
        cout << dq[i] << ' ';
    }
    return 0;
}
