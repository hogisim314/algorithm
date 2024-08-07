#include <iostream>
#include <algorithm> 
using namespace std;

/*
* 순서는 중요하지 않다.
* 같은 구성을 가질 때 
* +1, -1, 하나 바꿈
*/

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//입력
	int n;	cin >> n;
	string base,comp; cin >> base;

	//문제 해결
	int alpha[26] = { 0, }; //알파벳 구성이 어떻게 되어있는지
	int base_len = base.size();
	for (int i = 0; i < base_len; i++) { 
		alpha[base[i] - 'A'] += 1;
	}
	
	int count = 0;
	for (int i = 0; i < n - 1; i++) {
		cin >> comp;
		int comp_len = comp.size();
		int ccopy[26];
		copy(alpha, alpha + 26, ccopy); //배열 복제

		int same = 0;
		for (int i = 0; i < comp_len; i++) {
			if (ccopy[comp[i] - 'A'] > 0) {
				ccopy[comp[i] - 'A']--;
				same++;
			}
		}

		if (base_len == comp_len) { //두개의 길이가 같을 때
			if (same == base_len || same == base_len - 1) {
				//구성이 아예 같거나, 한글자가 다른경우
				count++;
			}
		}
		//기준 문자열이 한 글자 길 때 => 한 글자가 추가
		else if (base_len - 1 == comp_len && same == base_len - 1)
			count++;

		//기준 문자열이 한 글자 짧을 때 => 한 글자 삭제
		else if (base_len + 1 == comp_len && same == base_len)
			count++;
		else continue; 
	}

	//결과 출력
	cout << count << '\n';	
}