#include <math.h>
#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int sig[10][7] = {
    {1, 1, 1, 1, 1, 1, 0},  // 0
    {0, 1, 1, 0, 0, 0, 0},  // 1
    {1, 1, 0, 1, 1, 0, 1},  // 2
    {1, 1, 1, 1, 0, 0, 1},  // 3
    {0, 1, 1, 0, 0, 1, 1},  // 4
    {1, 0, 1, 1, 0, 1, 1},  // 5
    {1, 0, 1, 1, 1, 1, 1},  // 6
    {1, 1, 1, 0, 0, 0, 0},  // 7
    {1, 1, 1, 1, 1, 1, 1},  // 8
    {1, 1, 1, 1, 0, 1, 1}   // 9
};
int reversecnt[10][10];
string n, x;
string reversen, reversex;
int k, p;
int nnum, xnum;
int cnt = 0;

void print() {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cout << reversecnt[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void foo(int cur, int cost, string num) {
    if (cur == nnum) {
        if (cost <= p && stoi(num) <= stoi(n) && stoi(num) != stoi(x) &&
            stoi(num) != 0) {
            cnt++;
        }
        return;
    }
    for (int i = 0; i < 10; ++i) {
        string temp = num + (char)(i + '0');
        cost += reversecnt[i][x[cur] - '0'];
        foo(cur + 1, cost, temp);
        cost -= reversecnt[i][x[cur] - '0'];
    }
}

int main() {
    for (int i = 0; i < 9; ++i) {
        for (int j = i + 1; j < 10; ++j) {
            int cnt = 0;
            for (int k = 0; k < 7; ++k) {
                if (sig[i][k] != sig[j][k]) {
                    cnt++;
                }
            }
            reversecnt[i][j] = cnt;
            reversecnt[j][i] = cnt;
        }
    }

    cin >> n >> k >> p >> x;
    nnum = n.size();
    xnum = x.size();
    if (n.size() != x.size()) {
        for (int i = 0; i < nnum - xnum; ++i) {
            x = '0' + x;
        }
    }
    foo(0, 0, "");
    cout << cnt;
}
