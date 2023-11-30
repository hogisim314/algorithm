#include <iostream>
using namespace std;
int n, m;

bool visited[10];
int arr[10];

void f(int index) {
	if (index == m) {
		for (int i = 0; i < index; i++) {
			cout << arr[i]<<' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (visited[i]) continue;
		else {
			visited[i] = true;
			arr[index] = i;
			f(index + 1);
			arr[index] = 0;
			visited[i] = false;
		}
	}
}

int main() {
	cin >> n >> m;
	f(0);
}