#include <algorithm>
#include <iostream>
using namespace std;
int n;
int x, y;
pair<int, int> arr[50005];
bool visited[50005];
int cnt;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x >> y;
        arr[i].first = x;
        arr[i].second = y;
    }

    for (int i = 1; i <= n; ++i) {
        if (visited[i] || arr[i].second == 0) continue;
        visited[i] = true;
        int height = arr[i].second;
        cnt++;
        for (int j = i; j <= n; ++j) {
            if (arr[j].second > height)
                continue;
            else if (arr[j].second == height) {
                visited[j] = true;
            } else if (arr[j].second < height)
                break;
        }
    }
    cout << cnt;
}