#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

char arr[3][3];
string s;
bool emt = false;
int o_cnt, x_cnt;
bool flag;

bool check(char c) {
    // 행 검사
    for (int i = 0; i < 3; ++i) {
        if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] == c)
            return true;
    }
    // 열 검사
    for (int j = 0; j < 3; ++j) {
        if (arr[0][j] == arr[1][j] && arr[1][j] == arr[2][j] && arr[2][j] == c)
            return true;
    }
    // 대각선 검사
    if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] == c)
        return true;
    if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[0][2] == c)
        return true;
    return false;
}

int main() {
    while (true) {
        cin >> s;
        emt = false;
        o_cnt = 0;
        x_cnt = 0;
        flag = false;
        if (s == "end") break;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                arr[i][j] = s[i * 3 + j];
                if (arr[i][j] == '.') emt = true;
                if (arr[i][j] == 'O')
                    o_cnt++;
                else if (arr[i][j] == 'X')
                    x_cnt++;
            }
        }

        if (emt) {
            // 무조건 빙고 나와야함
            if (!(x_cnt - o_cnt == 1 || x_cnt - o_cnt == 0)) {
                flag = false;
            } else if (o_cnt == x_cnt) {
                // X에서 끝나면 안되고 o에서 끝나야함
                if (!check('X') && check('O')) flag = true;
            } else {
                // O에서 끝나면 안되고 x에서 끝나야함.
                if (!check('O') && check('X')) flag = true;
            }

        } else {
            if (x_cnt - o_cnt == 1) {  // 하나차이에서는 O로 성공하지 않는다는건
                                       // 당연해야하고 X로 성공할수도
                if (!check('O')) {
                    flag = true;
                } else
                    flag = false;
            } else
                flag = false;
        }
        if (!flag) {
            cout << "invalid" << '\n';
        } else {
            cout << "valid" << '\n';
        }
    }
}
