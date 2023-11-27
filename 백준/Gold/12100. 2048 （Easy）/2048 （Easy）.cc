#include <iostream>
#include <memory.h>
using namespace std;

int n, num, maxx = -1;
long long board[22][22]; // int가 저장하는 수. bool이 합쳤는지 안합쳤는지.
bool merged[22][22];

void move_2048(long long src[][22], int cnt);
void move_up(long long src[][22], int cnt);
void move_down(long long src[][22], int cnt);
void move_left(long long src[][22], int cnt);
void move_right(long long src[][22], int cnt);
void Input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> num;
            board[i][j] = num;
            merged[i][j] = false;
        }
    }
}

void move_up(long long src[][22], int cnt)
{
    memset(merged, 0, sizeof(merged));
    long long temp[22][22];
    memcpy(temp, src, sizeof(temp));

    for (int j = 1; j <= n; j++)
    { // 끝까지 붙이기
        for (int i = 1; i <= n; i++)
        {
            int idx = i; // 움직일 idx
            while (idx - 1 >= 1 && temp[idx - 1][j] == 0)
            {
                idx--;
            }
            if (idx == i)
                continue;
            else
            {
                temp[idx][j] = temp[i][j];
                merged[idx][j] = merged[i][j];
                temp[i][j] = 0;
                merged[i][j] = false;
            }
        }
    }

    for (int j = 1; j <= n; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (merged[i][j] == false && temp[i][j] == temp[i + 1][j])
            {
                temp[i][j] *= 2;
                temp[i + 1][j] = 0;
                merged[i][j] = true;
            }
        }
    }

    for (int j = 1; j <= n; j++)
    { // 끝까지 붙이기
        for (int i = 1; i <= n; i++)
        {
            int idx = i; // 움직일 idx
            while (idx - 1 >= 1 && temp[idx - 1][j] == 0)
            {
                idx--;
            }
            if (idx == i)
                continue;
            else
            {
                temp[idx][j] = temp[i][j];
                merged[idx][j] = merged[i][j];
                temp[i][j] = 0;
                merged[i][j] = false;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (temp[i][j] > maxx)
            {
                maxx = temp[i][j];
            }
        }
    }

    move_2048(temp, cnt);
}

void move_down(long long src[][22], int cnt)
{
    memset(merged, 0, sizeof(merged));
    long long temp[22][22];
    memcpy(temp, src, sizeof(temp));

    for (int j = 1; j <= n; j++)
    { // 끝까지 붙이기
        for (int i = n; i >= 1; i--)
        {
            int idx = i; // 움직일 idx
            while (idx + 1 <= n && temp[idx + 1][j] == 0)
            {
                idx++;
            }
            if (idx == i)
                continue;
            else
            {
                temp[idx][j] = temp[i][j];
                merged[idx][j] = merged[i][j];
                temp[i][j] = 0;
                merged[i][j] = false;
            }
        }
    }

    for (int j = 1; j <= n; j++)
    {
        for (int i = n; i >= 1; i--)
        {
            if (merged[i][j] == false && temp[i][j] == temp[i - 1][j])
            {
                temp[i][j] *= 2;
                temp[i - 1][j] = 0;
                merged[i][j] = true;
            }
        }
    }

    for (int j = 1; j <= n; j++)
    { // 끝까지 붙이기
        for (int i = n; i >= 1; i--)
        {
            int idx = i; // 움직일 idx
            while (idx + 1 <= n && temp[idx + 1][j] == 0)
            {
                idx++;
            }
            if (idx == i)
                continue;
            else
            {
                temp[idx][j] = temp[i][j];
                merged[idx][j] = merged[i][j];
                temp[i][j] = 0;
                merged[i][j] = false;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (temp[i][j] > maxx)
            {
                maxx = temp[i][j];
            }
        }
    }

    move_2048(temp, cnt);
}

void move_left(long long src[][22], int cnt)
{
    memset(merged, 0, sizeof(merged));
    long long temp[22][22];
    memcpy(temp, src, sizeof(temp));

    for (int i = 1; i <= n; i++)
    { // 끝까지 붙이기
        for (int j = 1; j <= n; j++)
        {
            int idx = j; // 움직일 idx
            while (idx - 1 >= 1 && temp[i][idx - 1] == 0)
            {
                idx--;
            }
            if (idx == j)
                continue;
            else
            {
                temp[i][idx] = temp[i][j];
                merged[i][idx] = merged[i][j];
                temp[i][j] = 0;
                merged[i][j] = false;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (merged[i][j] == false && temp[i][j] == temp[i][j + 1])
            {
                temp[i][j] *= 2;
                temp[i][j + 1] = 0;
                merged[i][j] = true;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    { // 끝까지 붙이기
        for (int j = 1; j <= n; j++)
        {
            int idx = j; // 움직일 idx
            while (idx - 1 >= 1 && temp[i][idx - 1] == 0)
            {
                idx--;
            }
            if (idx == j)
                continue;
            else
            {
                temp[i][idx] = temp[i][j];
                merged[i][idx] = merged[i][j];
                temp[i][j] = 0;
                merged[i][j] = false;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (temp[i][j] > maxx)
            {
                maxx = temp[i][j];
            }
        }
    }

    move_2048(temp, cnt);
}

void move_right(long long src[][22], int cnt)
{
    memset(merged, 0, sizeof(merged));
    long long temp[22][22];
    memcpy(temp, src, sizeof(temp));

    for (int i = 1; i <= n; i++)
    { // 끝까지 붙이기
        for (int j = n; j >= 1; j--)
        {
            int idx = j; // 움직일 idx
            while (idx + 1 <= n && temp[i][idx + 1] == 0)
            {
                idx++;
            }
            if (idx == j)
                continue;
            else
            {
                temp[i][idx] = temp[i][j];
                merged[i][idx] = merged[i][j];
                temp[i][j] = 0;
                merged[i][j] = false;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = n; j >= 1; j--)
        {
            if (merged[i][j] == false && temp[i][j] == temp[i][j - 1])
            {
                temp[i][j] *= 2;
                temp[i][j - 1] = 0;
                merged[i][j] = true;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    { // 끝까지 붙이기
        for (int j = n; j >= 1; j--)
        {
            int idx = j; // 움직일 idx
            while (idx + 1 <= n && temp[i][idx + 1] == 0)
            {
                idx++;
            }
            if (idx == j)
                continue;
            else
            {
                temp[i][idx] = temp[i][j];
                merged[i][idx] = merged[i][j];
                temp[i][j] = 0;
                merged[i][j] = false;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (temp[i][j] > maxx)
            {
                maxx = temp[i][j];
            }
        }
    }

    move_2048(temp, cnt);
}

void move_2048(long long src[][22], int cnt) // 현재까지 돌은 횟수
{
    if (cnt == 5)
    {
        return;
    }
    move_right(src, cnt + 1);
    move_up(src, cnt + 1);
    move_down(src, cnt + 1);
    move_left(src, cnt + 1);
}

int main()
{
    Input();
    move_2048(board, 0);
    cout << maxx;
}