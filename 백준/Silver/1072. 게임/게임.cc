#include<iostream>
using namespace std;
long long x, y, z;


int main() {
	cin >> x >> y;
	z = y * 100 / x;

	if (z >= 99) {
		cout << "-1" << endl;
		return 0;
	}
	int l = 0, r = x;

	while (l < r) {
		int piv = (l + r) / 2;
		if ((long long)(y + piv) * 100 / (long long)(x + piv) > z) {
			r = piv;
		}
		else {
			l = piv + 1;
		}
	}
	cout << r << endl;
}