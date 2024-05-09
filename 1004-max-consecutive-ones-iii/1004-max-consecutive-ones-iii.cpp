class Solution {
public:

    int longestOnes(vector<int>& nums, int k) {
        //k개를 다 쓰면 좋겠지. 
        //1. 첫번째 아이디어
        //nCk개로 0을 만든 다음 for문을 돌면서 최대 개수를 확인한다? -> 시간복잡도 터질듯
        //2. 두번쨰 아이디어
        //시작인덱스와 마지막 인덱스가 있어서 시작인덱스부터 1을세다가 0이 나오면 k를 소진하면서 0을 1로 생각한다. 0이 나왔는데 더이상
        //바꿀수없다면 그게 최대길이 그리고 그다음 iteration 때에는 마지막 인덱스 그 다음부터 카운트
        int l =0;
        int r = 0;
        int i=0;
        int cnt=k;
        int len=0;
        int maxx=0;
        while(true) {
            if (i>=nums.size()) {
                maxx = max(maxx, i-l);
                break;
            }
            if (nums[i]==1) {
                i++;
            }
            else if (nums[i]==0) {
                if (cnt==0) {
                    maxx = max(maxx, i-l);
                    while(true) {
                        if (nums[l]==1) {
                            l++;
                        }
                        else if (nums[l]==0) {
                            l++;
                            i=l;                            
                            break;
                        }
                    }
                    cnt = k;
                }
                else if (cnt!=0) {
                    cnt--;
                    i++;
                }
            }
        }
        return maxx;
    }
};