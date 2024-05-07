class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int ZeroIdx = -1; //가장 왼쪽의 0을 가리키는
        int nonZeroIdx = 0; // 안바뀐 숫자들의 인덱스를 가지는
        while(true) {
            if (nonZeroIdx == nums.size()) {
                break;
            }
            
            else if (nums[nonZeroIdx]!=0) {
                for (int i=0; i<nonZeroIdx; i++) {
                    if (nums[i]==0) {
                        ZeroIdx=i;
                        break;
                    }
                }
                if (ZeroIdx==-1) {
                    continue;
                }
                nums[ZeroIdx]=nums[nonZeroIdx];
                nums[nonZeroIdx] = 0;
                
            }
            nonZeroIdx++;
        }
    }
};