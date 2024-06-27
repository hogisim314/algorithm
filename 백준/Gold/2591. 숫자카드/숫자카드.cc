#include <iostream>
#include <cstring>
#define MAX_NUM 34
using namespace std;
char num[44];
int dp[44];

// 문자2개를 붙여서 숫자로 반환
int convertInt(char a, char b) {
    return ((a-'0') * 10) + (b-'0');
}


int main() {
    cin >> num;
    int len = strlen(num);


    dp[0] = 1; // 아래 반복문에서 i=2일때만 한번 사용됨. 정답을 위해 1로 둔다.
    dp[1] = num[len-1] == '0' ? 0 : 1; 

    if(len >= 2) {
        for(int i=2; i<=len; i++) {

            // 0인 경우 경우의 수 0가지
            if(num[len - i] == '0') {
                dp[i] = 0; continue;
            }

            int tmp = convertInt(num[len-i], num[len-i+1]);

            if( tmp <= MAX_NUM ) {
                dp[i] = dp[i-1]+dp[i-2];
            } else {
                dp[i] = dp[i-1];
            }

        }
    }
    cout << dp[len];
}