#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string s1, s2;
int num;
int ret_arabian(char c) {
    switch (c) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
    }
}

int get_sum(string s1, string s2) {
    int s1size = s1.size(), s2size = s2.size();
    int sum = 0;
    int n, next_n;
    for (int i = 0; i < s1size; i++) {
        n = ret_arabian(s1[i]);
        if (i + 1 < s1size) {
            next_n = ret_arabian(s1[i + 1]);
            if (n < next_n) {
                i++;
                sum += next_n - n;
            } else {
                sum += n;
            }
        } else {
            sum += n;
        }
    }

    for (int i = 0; i < s2size; i++) {
        n = ret_arabian(s2[i]);
        if (i + 1 < s2size) {
            next_n = ret_arabian(s2[i + 1]);
            if (n < next_n) {
                i++;
                sum += next_n - n;
            } else {
                sum += n;
            }
        } else {
            sum += n;
        }
    }

    return sum;
}

string convert_to_rome(int num) {
    string ret;
    int quotient = 0;
    for (int j = 1000; j >= 1; j /= 10) {
        if (num / j > 0) {
            quotient = num / j * j;
            num -= quotient;

            if (quotient >= 1000) {
                for (int i = 0; i < quotient / 1000; i++) {
                    ret += 'M';
                }
            } else if (quotient == 900) {
                ret += "CM";
            } else if (quotient >= 500) {
                ret += 'D';
                for (int i = 0; i < (quotient - 500) / 100; i++) {
                    ret += 'C';
                }
            } else if (quotient == 400) {
                ret += "CD";
            } else if (quotient >= 100) {
                for (int i = 0; i < quotient / 100; i++) {
                    ret += 'C';
                }
            } else if (quotient == 90) {
                ret += "XC";
            } else if (quotient >= 50) {
                ret += "L";
                for (int i = 0; i < (quotient - 50) / 10; i++) {
                    ret += 'X';
                }
            } else if (quotient == 40) {
                ret += "XL";
            } else if (quotient >= 10) {
                for (int i = 0; i < quotient / 10; i++) {
                    ret += "X";
                }
            } else if (quotient == 9) {
                ret += "IX";
            } else if (quotient >= 5) {
                ret += 'V';
                for (int i = 0; i < (quotient - 5); i++) {
                    ret += 'I';
                }
            } else if (quotient == 4) {
                ret += "IV";
            } else if (quotient >= 1) {
                for (int i = 0; i < (quotient); i++) {
                    ret += 'I';
                }
            }
        }
    }
    return ret;
}

int main() {
    cin >> s1 >> s2;
    num = get_sum(s1, s2);
    cout << num << '\n';
    cout << convert_to_rome(num);
}