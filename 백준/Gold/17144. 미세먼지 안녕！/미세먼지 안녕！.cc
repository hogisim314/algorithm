#include <iostream>
#include <memory.h>
using namespace std;
int r,c,t;
int room[1111][1111];
int temp[1111][1111];
int ans;
pair<int, int> airCondUp, airCondDown;

void timeFlow() {
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            if (room[i][j] == -1) {
                continue;
            }
            temp[i][j] = room[i][j] / 5;
        }
    }

    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            //동쪽
            if (j+1<=c-1) {
                room[i][j+1] +=temp[i][j];
                room[i][j] -= temp[i][j];
            }
            //서쪽
            if (j-1>=0 && room[i][j-1]!=-1) {
                room[i][j-1] +=temp[i][j];
                room[i][j] -= temp[i][j];
            }
            //남쪽
            if (i+1<=r-1 && room[i+1][j]!=-1) {
                room[i+1][j] +=temp[i][j];
                room[i][j] -= temp[i][j];
            }
            //북쪽
            if (i-1>=0 && room[i-1][j] != -1) {
                room[i-1][j] +=temp[i][j];
                room[i][j] -= temp[i][j];
            }
        }
    }

    memset(temp, 0, sizeof(temp));
}

void windUpper() {
    int curRow = airCondUp.first - 1;
    int curCol = airCondUp.second;

    room[curRow][curCol]= 0;

    int rowDirection = -1;
    int colDirection = 0;
    while(curRow + rowDirection>=0) {
        room[curRow][curCol]= room[curRow+rowDirection][curCol];
        curRow +=rowDirection;
    }

    rowDirection = 0;
    colDirection = +1;
    while(curCol + colDirection <=c-1) {
        room[curRow][curCol]=room[curRow][curCol+colDirection];
        curCol+=colDirection;
    }

    rowDirection = +1;
    colDirection = 0;
    while(curRow + rowDirection<=airCondUp.first) {
        room[curRow][curCol]=room[curRow+rowDirection][curCol];
        curRow+=rowDirection;
    }

    rowDirection = 0;
    colDirection = -1;
    while(curCol + colDirection>=1) {
        room[curRow][curCol]= room[curRow][curCol+colDirection];
        curCol+=colDirection;
    }

    room[airCondUp.first][airCondUp.second+1] = 0;
}

void windLower() {
    int curRow = airCondDown.first + 1;
    int curCol = airCondDown.second;

    room[curRow][curCol]= 0;

    int rowDirection = + 1;
    int colDirection = 0;
    while(curRow + rowDirection<=r-1) {
        room[curRow][curCol]= room[curRow+rowDirection][curCol];
        curRow +=rowDirection;
    }

    rowDirection = 0;
    colDirection = +1;
    while(curCol + colDirection <=c-1) {
        room[curRow][curCol]=room[curRow][curCol+colDirection];
        curCol+=colDirection;
    }

    rowDirection = -1;
    colDirection = 0;
    while(curRow + rowDirection>=airCondDown.first) {
        room[curRow][curCol]=room[curRow+rowDirection][curCol];
        curRow+=rowDirection;
    }

    rowDirection = 0;
    colDirection = -1;
    while(curCol + colDirection>=1) {
        room[curRow][curCol]= room[curRow][curCol+colDirection];
        curCol+=colDirection;
    }
    room[airCondDown.first][airCondDown.second+1] = 0;
}

void sum() {
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            if (room[i][j] == -1) {
                continue;
            }
            ans+=room[i][j];
        }
    }
}

int cnt;
int main() {
    cin>>r>>c>>t;
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            cin>>room[i][j];
            if (cnt ==0 && room[i][j] == -1) {
                airCondUp.first = i;
                airCondUp.second = j;
                cnt++;
            }
            else if (cnt == 1 && room[i][j] == -1) {
                airCondDown.first = i;
                airCondDown.second = j;
            }
        }
    }
    while(t--) {
        timeFlow();
        windUpper();
        windLower();
    }
    sum(); 
    cout<<ans;

}