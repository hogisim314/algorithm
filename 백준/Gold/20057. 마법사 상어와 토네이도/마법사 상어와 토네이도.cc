#include <math.h>

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n;

int mapp[500][500];                   // 초기 모래 2차원 배열
int tornadoDirRow[] = {0, 1, 0, -1};  // 0 1 2 3
int tornadoDirCol[] = {-1, 0, 1, 0};  // 0 1 2 3
int curDir = 0;
int tornadoDist = 1;
int rotateCnt = 1;
int curRow, curCol;
int ans;

void print() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << mapp[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

bool is_inside(int i, int j) {
    if (i < 1 || i > n || j < 1 || j > n) {
        return false;
    }
    return true;
}

void sandMove(int prevRow, int prevCol, int dir) {
    int verticalDir;
    if (dir % 2 == 0) {   // 짝수면
        verticalDir = 1;  // verticalDir / verticalDir + 2 사용
    }
    if (dir % 2 == 1) {   // 홀수면
        verticalDir = 0;  // verticalDir / verticalDir + 2 사용
    }
    int xrow = prevRow;
    int xcol = prevCol;
    int yrow = xrow + tornadoDirRow[dir];
    int ycol = xcol + tornadoDirCol[dir];
    int arow = yrow + tornadoDirRow[dir];
    int acol = ycol + tornadoDirCol[dir];

    int initialVal = mapp[yrow][ycol];
    int tempval = initialVal;
    // 1프로짜리
    if (is_inside(xrow + tornadoDirRow[verticalDir],
                  xcol + tornadoDirCol[verticalDir])) {
        mapp[xrow + tornadoDirRow[verticalDir]]
            [xcol + tornadoDirCol[verticalDir]] += floor(initialVal * 0.01);
    } else {
        ans += floor(initialVal * 0.01);
    }
    tempval -= floor(initialVal * 0.01);

    if (is_inside(xrow + tornadoDirRow[verticalDir + 2],
                  xcol + tornadoDirCol[verticalDir + 2])) {
        mapp[xrow + tornadoDirRow[verticalDir + 2]]
            [xcol + tornadoDirCol[verticalDir + 2]] += floor(initialVal * 0.01);
    } else {
        ans += floor(initialVal * 0.01);
    }
    tempval -= floor(initialVal * 0.01);

    // 7프로짜리
    if (is_inside(yrow + tornadoDirRow[verticalDir],
                  ycol + tornadoDirCol[verticalDir])) {
        mapp[yrow + tornadoDirRow[verticalDir]]
            [ycol + tornadoDirCol[verticalDir]] += floor(initialVal * 0.07);
    } else {
        ans += floor(initialVal * 0.07);
    }
    tempval -= floor(initialVal * 0.07);

    if (is_inside(yrow + tornadoDirRow[verticalDir + 2],
                  ycol + tornadoDirCol[verticalDir + 2])) {
        mapp[yrow + tornadoDirRow[verticalDir + 2]]
            [ycol + tornadoDirCol[verticalDir + 2]] += floor(initialVal * 0.07);
    } else {
        ans += floor(initialVal * 0.07);
    }
    tempval -= floor(initialVal * 0.07);

    // 2프로짜리
    if (is_inside(yrow + (2 * tornadoDirRow[verticalDir]),
                  ycol + (2 * tornadoDirCol[verticalDir]))) {
        mapp[yrow + (2 * tornadoDirRow[verticalDir])]
            [ycol + (2 * tornadoDirCol[verticalDir])] +=
            floor(initialVal * 0.02);
    } else {
        ans += floor(initialVal * 0.02);
    }
    tempval -= floor(initialVal * 0.02);

    if (is_inside(yrow + (2 * tornadoDirRow[verticalDir + 2]),
                  ycol + (2 * tornadoDirCol[verticalDir + 2]))) {
        mapp[yrow + (2 * tornadoDirRow[verticalDir + 2])]
            [ycol + (2 * tornadoDirCol[verticalDir + 2])] +=
            floor(initialVal * 0.02);
    } else {
        ans += floor(initialVal * 0.02);
    }
    tempval -= floor(initialVal * 0.02);

    // 10프로짜리
    if (is_inside(arow + tornadoDirRow[verticalDir],
                  acol + tornadoDirCol[verticalDir])) {
        mapp[arow + tornadoDirRow[verticalDir]]
            [acol + tornadoDirCol[verticalDir]] += floor(initialVal * 0.1);
    } else {
        ans += floor(initialVal * 0.1);
    }
    tempval -= floor(initialVal * 0.1);

    if (is_inside(arow + tornadoDirRow[verticalDir + 2],
                  acol + tornadoDirCol[verticalDir + 2])) {
        mapp[arow + tornadoDirRow[verticalDir + 2]]
            [acol + tornadoDirCol[verticalDir + 2]] += floor(initialVal * 0.1);

    } else {
        ans += floor(initialVal * 0.1);
    }
    tempval -= floor(initialVal * 0.1);

    if (is_inside(arow + tornadoDirRow[dir], acol + tornadoDirCol[dir])) {
        mapp[arow + tornadoDirRow[dir]][acol + tornadoDirCol[dir]] +=
            floor(initialVal * 0.05);

    } else {
        ans += floor(initialVal * 0.05);
    }
    tempval -= floor(initialVal * 0.05);

    // cout << tempval << '\n';
    if (is_inside(arow, acol)) {
        mapp[arow][acol] += tempval;
    } else {
        ans += tempval;
    }
    mapp[yrow][ycol] = 0;
}

void tornadoMove() {
    // cout << curRow << ' ' << curCol << '\n';
    if (curRow == 1) {
        tornadoDist -= 1;
    }
    for (int i = 1; i <= tornadoDist; i++) {
        sandMove(curRow, curCol, curDir);
        int nextRow = curRow + tornadoDirRow[curDir];
        int nextCol = curCol + tornadoDirCol[curDir];
        curRow = nextRow;
        curCol = nextCol;
    }
    curDir++;
    if (curDir == 4) {
        curDir = 0;
    }

    if (rotateCnt == 1) {
        rotateCnt++;
    } else if (rotateCnt == 2) {
        rotateCnt = 1;
        tornadoDist++;
    }
}

int main() {
    cin >> n;
    curRow = n / 2 + 1;
    curCol = n / 2 + 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> mapp[i][j];
        }
    }

    while (true) {
        if (curRow == 1 && curCol == 1) break;
        tornadoMove();
        // print();
    }

    cout << ans;
    return 0;
}