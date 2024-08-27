#include <algorithm>
#include <iostream>
using namespace std;
int n;
int num;
int grid[6][6];
bool visited[6][6];
int ans;

void del(int k) {
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            if (grid[i][j] == num) {
                visited[i][j] = true;
                return;
            }
        }
    }
}

void check() {
    ans = 0;
    for (int i = 1; i <= 5; i++) {
        if (visited[i][1] == true && visited[i][2] == true &&
            visited[i][3] == true && visited[i][4] == true &&
            visited[i][5] == true) {
            ans++;
        }
    }

    for (int j = 1; j <= 5; j++) {
        if (visited[1][j] == true && visited[2][j] == true &&
            visited[3][j] == true && visited[4][j] == true &&
            visited[5][j] == true) {
            ans++;
        }
    }

    if (visited[1][1] == true && visited[2][2] == true &&
        visited[3][3] == true && visited[4][4] == true &&
        visited[5][5] == true) {
        ans++;
    }

    if (visited[1][5] == true && visited[2][4] == true &&
        visited[3][3] == true && visited[4][2] == true &&
        visited[5][1] == true) {
        ans++;
    }
}

int main() {
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            cin >> num;
            del(num);
            check();
            if (ans >= 3) {
                cout << (i - 1) * 5 + j;
                return 0;
            }
        }
    }
}