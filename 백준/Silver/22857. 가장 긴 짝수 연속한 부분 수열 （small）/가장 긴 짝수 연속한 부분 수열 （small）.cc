#include <iostream>
#include <algorithm>
using namespace std;
int n, k;
int arr[1000100];
int s = 1, e = 1;
int odd;
int cnt;
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    while (true)
    {
        if (s > n || e > n)
        {
            break;
        }
        if (odd <= k)
        {
            if (arr[e] % 2 != 0)
            {
                odd++;
            }
            if (odd<=k) {
                cnt = max(cnt,(e - s + 1) - odd);
                e++;
            }
        }
        else if (odd > k)
        {
            while (odd > k)
            {
                cnt = max(cnt,(e - s + 1) - odd);
                if (arr[s] % 2 != 0)
                {
                    odd--;
                }
                s++;
            }
            e++;
        }
    }
    cout << cnt;
}
