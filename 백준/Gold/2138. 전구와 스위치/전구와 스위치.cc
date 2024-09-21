#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define MAXNUM 100005
int n;
string existingState;
string desiredState;

string es1, es2;  // es1이0번째 누른 버전, es2가 안누른 버전
int ans1, ans2;

char convert(char c) {
    if (c == '0')
        return '1';
    else
        return '0';
}

int main() {
    cin >> n;
    cin >> existingState;
    cin >> desiredState;

    es1 = es2 = existingState;

    // 0번 누를때
    ans1++;
    es1[0] = convert(es1[0]);
    es1[1] = convert(es1[1]);

    // cout << es1 << ' ' << es2 << '\n';
    for (int i = 1; i < n - 1; ++i) {
        if (es1[i - 1] != desiredState[i - 1]) {
            ans1++;
            es1[i - 1] = convert(es1[i - 1]);
            es1[i] = convert(es1[i]);
            es1[i + 1] = convert(es1[i + 1]);
        }

        if (es2[i - 1] != desiredState[i - 1]) {
            ans2++;
            es2[i - 1] = convert(es2[i - 1]);
            es2[i] = convert(es2[i]);
            es2[i + 1] = convert(es2[i + 1]);
        }
    }
    // cout << es1 << ' ' << es2 << '\n';
    if (es1[n - 2] != desiredState[n - 2]) {
        ans1++;
        es1[n - 2] = convert(es1[n - 2]);
        es1[n - 1] = convert(es1[n - 1]);
    }

    if (es2[n - 2] != desiredState[n - 2]) {
        ans2++;
        es2[n - 2] = convert(es2[n - 2]);
        es2[n - 1] = convert(es2[n - 1]);
    }
    // cout << es1 << ' ' << es2 << '\n';
    if (es1 != desiredState) {
        ans1 = -1;
    }

    if (es2 != desiredState) {
        ans2 = -1;
    }

    if (ans1 == -1) {
        cout << ans2;
        return 0;
    } else if (ans2 == -1) {
        cout << ans1;
        return 0;
    } else {
        cout << min(ans1, ans2);
    }
}