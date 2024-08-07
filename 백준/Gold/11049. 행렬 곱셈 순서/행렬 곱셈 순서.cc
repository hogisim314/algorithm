#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <climits>
using namespace std;

int n, r, c;
vector<pair<int, int> > v;
int arr[505][505];

int main() {
	cin >> n;
	v.push_back(make_pair(0, 0));//index1부터 하려고
	for (int i = 0; i < n; i++) {
		cin >> r >> c;
		v.push_back(make_pair(r, c));
	}

	for (int l = 2; l <= n; l++) {//line 몇개 관찰 
		for (int i = 1; i <= n - l + 1; i++) {//시작 위치
			int j = i + l - 1;//j는 i부터 몇개 관찰할건지/ end point
			arr[i][j] = INT_MAX;
			for (int k = i; k <= j - 1; k++) {
				int q = arr[i][k] + arr[k + 1][j] + v[i].first * v[k].second * v[j].second;
				if (q < arr[i][j]) {
					arr[i][j] = q;
				}
			}
		}
	}
	cout << arr[1][n];
}