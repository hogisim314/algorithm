#include <iostream>
#include <algorithm>
#include <memory.h>
#define PICK 6
using namespace std;
int k;
int arr[15];
bool visited[15];
int combi[15];

void f(int idx, int cur) // idx는 배열에서 어디를 봐야하는지, cur는 정답출력배열에 어디를 넣어야 하는지
{
    combi[cur] = arr[idx];

    if (cur == PICK)
    {
        for (int i = 1; i <= PICK; i++)
        {
            cout << combi[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = idx; i < k; i++)
    {
        if (cur == PICK)
        {
            f(i + 1, cur);
        }
        f(i + 1, cur + 1);
    }
}
int main()
{
    while (true)
    {
        memset(arr, 0, sizeof(arr));
        memset(visited, false, sizeof(visited));
        memset(combi, 0, sizeof(combi));
        cin >> k;
        if (k == 0)
            return 0;
        for (int i = 1; i <= k; i++)
        {
            cin >> arr[i];
        }
        sort(arr + 1, arr + k + 1);
        for (int i = 1; i <= k - PICK + 1; i++)
        {
            f(i, 1);
        }
        cout << '\n';
    }
}