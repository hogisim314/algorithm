#include <iostream>
using namespace std;
int h, w, n, m;
int p, q;
int main() {
	cin >> h >> w >> n >> m;
	if (h % (n + 1) == 0) {
		p = h / (n + 1);
	}
	else {
		p = h / (n + 1) + 1;
	}

	if (w % (m + 1) == 0) {
		q = w / (m + 1);
	}
	else {
		q = w / (m + 1) + 1;
	}
	cout << p * q;
}