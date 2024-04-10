#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N;
int arr[22][22];
int minn = 10000;
int teamA[22];
int teamB[22];
bool visited[22];

void get_diff() {
    int sumA = 0, sumB = 0;
    int mem1, mem2;
    for (int i = 1; i <= N / 2; i++) {
        mem1 = teamA[i];
        for (int j = 1; j <= N / 2; j++) {
            mem2 = teamA[j];
            if (mem1 == mem2) continue;
            sumA += arr[mem1][mem2];
        }
    }

    for (int i = 1; i <= N / 2; i++) {
        mem1 = teamB[i];
        for (int j = 1; j <= N / 2; j++) {
            mem2 = teamB[j];
            if (mem1 == mem2) continue;
            sumB += arr[mem1][mem2];
        }
    }

    minn = min(minn, abs(sumA - sumB));
    return;
}

void combi(int depth, int nextIdx) {
    if (depth == N / 2 + 1) {
        int idx = 1;
        for (int i = 1; i <= N; i++) {
            if (!visited[i]) {
                teamB[idx++] = i;
            }
        }
        get_diff();
        return;
    }

    for (int i = nextIdx; i <= N; i++) {
        visited[i] = true;
        teamA[depth] = i;
        combi(depth + 1, i + 1);
        visited[i] = false;
    }
}

void input() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
        }
    }
}

void solution() {
    combi(1, 1);
    cout << minn << '\n';
}

int main() {
    input();
    solution();
}