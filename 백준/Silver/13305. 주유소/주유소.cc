#include <iostream>
#include <algorithm>
using namespace std;
int n;
int road[111111]; // 거리
int city[111111]; // 기름값
int minn;
int minidx, sec_min_idx;
int cost;
// st에서 ed까지 최소를 찾고
// 그 최소로부터 ed까지의 비용을 계산한다.
// 그리고 다시 st~minidx-1까지 이 함수 반복한다.
void f(int st, int ed)
{
    if (st == ed)
        return;
    int len = ed - st + 1;
    vector<pair<int, int> > v;
    for (int i = 1; i < len; i++)
    {
        v.push_back(make_pair(city[i], i));
    }
    sort(v.begin(), v.end());
    minn = v[0].first;
    minidx = v[0].second;
    for (int i = minidx; i < ed; i++)
    {
        cost += (minn * road[i]);
    }

    f(st, minidx);
}

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
        if (i != n - 1)
        {
            minn = min(city[i], minn);
            minidx = i;
        }
    }

    f(1, n);
    cout << cost;
}
