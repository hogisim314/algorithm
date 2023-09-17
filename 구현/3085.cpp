#include <iostream>
#include <algorithm>
using namespace std;

char board[55][55];
int n, ans;//글로벌 최대 길이 변수
void getLongest() {
    for (int i=0; i<n; i++) {
        char cur = board[i][0];//먼저 처음 인덱스를 잡은 후 가로로 찾아나간다.
        int temp=0;//최대 길이를 저장할 변수
        for (int j=0; j<n; j++) {
            temp++;
            while(cur==board[i][j+1]) {
                j++;
                temp++;
            }
            cur = board[i][j+1];
            ans = max(ans, temp);
            temp=0;
        }
    }

    for (int j=0; j<n; j++) {
        char cur = board[0][j];
        int temp=0;
        for (int i=0; i<n; i++) {
            temp++;
            while(cur==board[i+1][j]) {
                i++;
                temp++;
            }
            cur = board[i+1][j];
            ans = max(ans,temp);
            temp=0;
        }
    }
}

int main() {
    cin>>n;
     for (int i=0; i<n; i++) {
         for (int j=0; j<n; j++) {
             cin>>board[i][j];
         }
     }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n-1; j++) {
            swap(board[i][j], board[i][j+1]);
            getLongest();
            swap(board[i][j], board[i][j+1]);
        }
    }
    
    for (int j=0; j<n; j++) {
        for (int i=0; i<n-1; i++) {
            swap(board[i][j], board[i+1][j]);
            getLongest();
            swap(board[i][j], board[i+1][j]);
        }
    }

    cout<<ans;
}
