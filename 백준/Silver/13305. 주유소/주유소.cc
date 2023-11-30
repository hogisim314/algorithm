#include <iostream>
#include <algorithm>
using namespace std;
int n;
long long road[111111]; // 거리
long long city[111111]; // 기름값
long long minn;
long long cost;

int main()
{
    cin >> n;
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> road[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> city[i];
    }  
    minn = city[1];
    for (int i=1; i<=n-1; i++) {
        cost += (minn*road[i]);

        if (city[i+1]<minn) {
            minn = city[i+1];
        }
    }
    cout << cost;
}
