class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int cnt=0;
        for (int i=0; i<n; i++) { //row 확인
            for (int j=0; j<n; j++) { // col 확인
                bool same = true;
                for (int k=0; k<n; k++) {
                    if (grid[i][k]!=grid[k][j]) {
                        same = false;
                        break;
                    }
                }
                if (same) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};