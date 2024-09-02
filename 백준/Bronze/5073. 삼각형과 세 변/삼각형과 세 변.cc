#include <iostream>
#include <algorithm>
using namespace std;
int a, b, c;
int MAX;
int main() {
	while (true) {
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0) {
			break;
		}
		MAX = max(a, max(b, c));
		if (MAX == a) {
			if (a >= (b + c)) {
				cout << "Invalid" << '\n';
				continue;
			}
		}
		else if (MAX == b) {
			if (b >= (a + c)) {
				cout << "Invalid" << '\n';
				continue;
			}
		}
		else if (MAX == c) {
			if (c >= (b + a)) {
				cout << "Invalid" << '\n';
				continue;
			}
		}

		if (a == b && b == c) {
			cout << "Equilateral" << '\n';
		}
		else if (a == b || b == c || c==a) {
			cout << "Isosceles" << '\n';
		}
		else if (a != b && b != c) {
			cout << "Scalene" << '\n';
		}
	}
}