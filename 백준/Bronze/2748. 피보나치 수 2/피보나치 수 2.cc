#include <algorithm>
#include <iostream>
using namespace std;
int n;
long long fibo[100];
int main() {
    cin >> n;
    fibo[0] = 0;
    fibo[1] = 1;
    for (int i = 2; i <= n; i++) {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }
    cout << fibo[n];
}