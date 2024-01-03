#include <memory.h>

#include <algorithm>
#include <iostream>

using namespace std;
long arr[205];
bool visited[205];
long ans[205];
long idx = 0;
int main(int argc, char** argv) {
    int test_case;
    int T;

    // freopen("input.txt", "r", stdin);
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case) {
        idx = 0;
        memset(visited, 0, sizeof(visited));
        memset(arr, 0, sizeof(arr));
        memset(ans, 0, sizeof(ans));
        int num;
        cin >> num;
        for (int i = 1; i <= 2 * num; i++) {
            cin >> arr[i];
        }

        for (int i = 1; i <= 2 * num; i++) {
            if (visited[i]) continue;
            visited[i] = true;
            long origin = arr[i] * 4 / 3;
            for (int j = i + 1; j <= 2 * num; j++) {
                if (!visited[j] && arr[j] == origin) {
                    ans[idx] = arr[i];
                    visited[j] = true;
                    idx++;
                    break;
                }
            }
        }
        cout << "Case #" << test_case << ": ";
        for (int i = 0; i < idx; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
    return 0;  // 정상종료시 반드시 0을 리턴해야합니다.
}