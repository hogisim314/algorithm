#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;
int cnt;
int main() {

	string s1,s2;
	getline(cin, s1);
	stringstream ss(s1);
	while (ss >> s2) {
		cnt++;
	}
	cout << cnt;
}
