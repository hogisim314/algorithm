#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
int P;
int result;
int students[22];
int h;
int idx;
int main() {
    cin >> P;
    for (int p = 1; p <= P; p++) {
        result = 0;
        cin >> idx;
        for (int i = 0; i < 20; i++) cin >> students[i];
        for (int i = 0; i < 20; i++) {
            for (int j = i; j < 20; j++) {
                if (students[i] > students[j]) result += 1;
            }
        }
        cout << p << ' ' << result << '\n';
    }
}