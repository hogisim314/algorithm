#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <stack>
#define LIMIT 1'000'000'000
using namespace std;
string cmd;
int arr[11111];
vector<string> cmd_list;
vector<int> num_list;
int N;

void do_interpretation(int num) {
	stack<int> s;
	s.push(num);
	int idx = 0; //num_list를 바라보는 변수
	for (int i = 0; i < cmd_list.size(); i++) {
		cmd = cmd_list[i];
		if (cmd == "END") break;
		else  if (cmd == "NUM") {
			s.push(num_list[idx]);
			idx++;
		}
		else  if (cmd == "POP") {
			if (s.empty()) {
				cout << "ERROR" << '\n';
				return;
			}
			s.pop();
		}
		else  if (cmd == "INV") {
			if (s.empty()) {
				cout << "ERROR" << '\n';
				continue;
			}
			int top = s.top();
			s.pop();
			s.push(-top);
		}
		else  if (cmd == "DUP") {
			if (s.empty()) {
				cout << "ERROR" << '\n';
				return;
			}
			s.push(s.top());
		}
		else  if (cmd == "SWP") {
			if (s.size() < 2) {
				cout << "ERROR" << '\n';
				return;
			}
			int tp = s.top();
			s.pop();

			int sec = s.top();
			s.pop();

			s.push(tp);
			s.push(sec);
		}
		else  if (cmd == "ADD") {
			if (s.size() < 2) {
				cout << "ERROR" << '\n';
				return;
			}
			int tp = s.top();
			s.pop();

			int sec = s.top();
			s.pop();
			long long res = (long long)tp + sec;
			if (abs(res) > LIMIT) {
				cout << "ERROR" << '\n';
				return;
			}
			s.push(tp + sec);
			
		}
		else  if (cmd == "SUB") {
			if (s.size() < 2) {
				cout << "ERROR" << '\n';
				return;
			}
			int tp = s.top();
			s.pop();

			int sec = s.top();
			s.pop();
			long long res = (long long)sec - tp;
			if (abs(res) > LIMIT) {
				cout << "ERROR" << '\n';
				return;
			}
			s.push(sec-tp);
		}
		else  if (cmd == "MUL") {
			if (s.size() < 2) {
				cout << "ERROR" << '\n';
				return;
			}
			int tp = s.top();
			s.pop();

			int sec = s.top();
			s.pop();
			long long res = (long long)tp * sec;

			if (abs(res) > LIMIT) {
				cout << "ERROR" << '\n';
				return;
			}
			s.push(tp * sec);
		}
		else  if (cmd == "DIV") {
			if (s.size() < 2) {
				cout << "ERROR" << '\n';
				return;
			}
			int tp = s.top();
			if (tp == 0) {
				cout << "ERROR" << '\n';
				return;
			}
			s.pop();

			int sec = s.top();
			s.pop();

			s.push(sec / tp);
		}
		else  if (cmd == "MOD") {
			if (s.size() < 2) {
				cout << "ERROR" << '\n';
				return;
			}
			int tp = s.top();
			if (tp == 0) {
				cout << "ERROR" << '\n';
				return;
			}
			s.pop();

			int sec = s.top();
			s.pop();

			if (sec < 0) {
				s.push(-abs(sec%tp));
			}
			else if (sec > 0) {
				s.push(+abs(sec%tp));
			}
			else {
				s.push(0);
			}
		}
	}
	if (s.size() != 1) {
		cout << "ERROR" << '\n';
		return;
	}
	cout << s.top() << '\n';
	return;
}

void do_instruction() {
	for (int i = 0; i < N; i++) {
		do_interpretation(arr[i]);
	}
}

int main() {
	while (true) {
		cmd_list.clear();
		num_list.clear();
		while (true) {
			cin >> cmd;
			if (cmd == "QUIT") {
				return 0;
			}
			if (cmd == "END") {
				cin >> N;
				for (int i = 0; i < N; i++) {
					cin >> arr[i];
				}
				do_instruction();
				cout << '\n';
				break;
			}
			if (cmd == "NUM") {
				int x;
				cin >> x;
				num_list.push_back(x);
			}
			cmd_list.push_back(cmd);
		}
	}
}
