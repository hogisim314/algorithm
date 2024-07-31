#include <algorithm>
#include <iostream>
#include <deque>
#include <string>
using namespace std;
int n;
string cmd;
deque<int> dq;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> cmd;
		if (cmd == "push") {
			int x;
			cin >> x;
			dq.push_back(x);
		}
		else if (cmd == "pop") {
			if (dq.empty()) {
				cout << "-1" << '\n';
				continue;
			}
			cout << dq.front() << '\n';
			dq.pop_front();

		}
		else if (cmd == "size") {
			cout << dq.size() << '\n';
		}
		else if (cmd == "empty") {
			if (dq.empty()) {
				cout << 1 << '\n';
			}
			else
				cout << 0 << '\n';
		}
		else if (cmd == "front") {
			if (dq.empty()) {
				cout << "-1" << '\n';
				continue;
			}
			cout << dq.front() << '\n';
		}
		else if (cmd == "back") {
			if (dq.empty()) {
				cout << "-1" << '\n';
				continue;
			}
			cout << dq.back() << '\n';
		}
	}
}