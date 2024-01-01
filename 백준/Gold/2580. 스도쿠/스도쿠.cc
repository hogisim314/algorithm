#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sudoku[11][11];
vector<pair<int, int> > zero;
bool found = false;

bool check(int row, int col)
{
    int checkNum = sudoku[row][col];
    for (int i = 1; i <= 9; i++)
    {
        if (i == col)
            continue;
        if (sudoku[row][i] == checkNum)
            return false;
    }

    for (int i = 1; i <= 9; i++)
    {
        if (i == row)
            continue;
        if (sudoku[i][col] == checkNum)
            return false;
    }

    int sti = (row - 1) / 3 * 3 + 1;
    int stj = (col - 1) / 3 * 3 + 1;
    int edi = sti + 2;
    int edj = stj + 2;

    for (int i = sti; i <= edi; i++)
    {
        for (int j = stj; j <= edj; j++)
        {
            if (i == row && j == col)
                continue;
            if (sudoku[i][j] == checkNum)
                return false;
        }
    }

    return true;
}

void solve(int fill) // 배열의 index & 얼마만큼 채웠는지 나타내는 fill
{
    if (fill == zero.size())
    { // 다 채웠으면 끝내야함.
        for (int i = 1; i <= 9; i++)
        {
            for (int j = 1; j <= 9; j++)
            {
                cout << sudoku[i][j] << ' ';
            }
            cout << '\n';
        }
        found = true;
        return;
    }
    int row = zero[fill].first;
    int col = zero[fill].second;
    for (int num = 1; num <= 9; num++)
    {
        sudoku[row][col] = num;
        if (check(row, col))
        { // 갈 수 있으면 ok
            solve(fill + 1);
        }
        if (found) {
            return;
        }
        sudoku[row][col] = 0;
    }        
}

int main()
{
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            cin >> sudoku[i][j];
            if (sudoku[i][j] == 0)
            {
                zero.push_back(make_pair(i, j));
            }
        }
    }

    solve(0);

    return 0;
}