#include <algorithm>
#include <iostream>
using namespace std;
int arr[10];
int parr[10];

void combi(int depth, int lastIdx) {
    if (depth == 7) {
        int sum = 0;
        for (int i = 0; i < 7; i++) {
            sum += parr[i];
        }
        if (sum == 100) {
            for (int i = 0; i < 7; i++) {
                cout << parr[i] << '\n';
            }
            exit(0);
        }
    }
    for (int i = lastIdx; i < 9; i++) {
        parr[depth] = arr[i];
        combi(depth + 1, i + 1);
    }
}

int main() {
    for (int i = 0; i < 9; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + 9);
    combi(0, 0);
}