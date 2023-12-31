#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int k;
int num;
int arr[3000];
vector<int> levels[11];

void f(int st, int ed, int depth)
{

    int len = (ed - st + 1);
    int mid = len / 2 + st;

    levels[depth].push_back(arr[mid]);

    if (depth == k)
    {
        return;
    }
    f(st, mid - 1, depth + 1);
    f(mid + 1, ed, depth + 1);
}

int main()
{
    cin >> k;
    num = (int)(pow(2, k)) - 1;
    for (int i = 1; i <= num; i++)
    {
        cin >> arr[i];
    }

    f(1, num, 1);

    for (int i = 1; i <= k; i++)
    { // i번째 층 출력
        for (int j = 0; j < levels[i].size(); j++)
        {
            cout << levels[i][j] << ' ';
        }
        cout << '\n';
    }
}