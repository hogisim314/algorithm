#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,m;
int arr[10];
bool selected[10];
void combination(int Cnt);
vector<int> v;
int main() {
	cin>>n>>m;
	for (int i=0; i<n; ++i) {
		cin>>arr[i];
	}
	sort(arr, arr+n);
	combination(0);
	return 0;
}

void combination(int Cnt) {
	if (Cnt==m) {
		for (int i=0; i<v.size(); ++i)
		{
			cout<<v[i]<<' ';
		}
		cout<<'\n';
		return;
	}
	
	for (int i=0; i<n; ++i) {
		if (selected[i]) continue;
		selected[i]=true;
		v.push_back(arr[i]);
		combination(Cnt+1);
		selected[i]=false;
		v.pop_back();
	}
}