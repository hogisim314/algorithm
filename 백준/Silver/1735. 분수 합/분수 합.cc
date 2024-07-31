#include <algorithm>
#include <iostream>
using namespace std;
int a, b, c, d;

int get_gcd(int p, int q) {
    int r;
    while (q != 0) {
        r = p % q;
        p = q;
        q = r;
    }
    return p;
}

int get_lcm(int p, int q) { return p * q / get_gcd(p, q); }

int main() {
    cin >> a >> b >> c >> d;
    int lcm = get_lcm(b, d);
    a *= lcm / b;
    b = lcm;
    c *= lcm / d;
    d = lcm;

    int denom = lcm;
    int num = a + c;

    int gcd = get_gcd(denom, num);
    denom /= gcd;
    num /= gcd;
    cout << num << ' ' << denom;
    return 0;
    // 약분 되는지 확인해야함.
}