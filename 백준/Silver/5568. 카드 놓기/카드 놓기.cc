#include <algorithm>
#include <iostream>
#include <set>
#include <string>
using namespace std;
int n, k;
int arr[15];
int parr[15];
bool visited[15];
set<string> s;
void combi(int depth) {
    if (depth == k + 1) {
        string temp = "";
        for (int i = 1; i <= k; i++) {
            temp += to_string(parr[i]);
        }
        // cout << temp << ' ';
        s.insert(temp);
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;
        visited[i] = true;
        parr[depth] = arr[i];
        combi(depth + 1);
        visited[i] = false;
    }
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    combi(1);
    cout << s.size();
}