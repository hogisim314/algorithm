#include <iostream>
#include <math.h>
#include <memory.h>
using namespace std;
int n;

bool arr[540000];

void f(int s, int e) {
	if (s == e) {
		arr[s] = false;
		return;
	}
	int len = (e - s + 1)/3;
	for (int i = s; i < s+len; i++) {
		arr[i] = false;
	}
	for (int i = s + len; i < s + 2 * len; i++) {
		arr[i] =true;
	}
	for (int i = s + 2 * len; i <= e; i++) {
		arr[i] = false;
	}
	f(s, s + len - 1);
	f(s + 2 * len, e);
}

int main() {
	while (cin>>n) {
		f(1, pow(3, n));//1 base index 사용
		for (int i = 1; i <= pow(3, n); i++) {
			if (arr[i] == false) {
				cout << "-";
			}
			else cout << " ";
		}
		cout << '\n';
		memset(arr, 0, sizeof(arr));
	}
}