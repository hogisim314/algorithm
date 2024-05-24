class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroIdx = 0;
        bool found = false;
        for (int i=0; i<nums.size(); i++) {
            if (!found && nums[i]==0) {
                zeroIdx = i;
                found = true;
            }
            else if (nums[i]!=0) {
                if (found) {
                    nums[zeroIdx] = nums[i];
                    nums[i] = 0;
                    found = true;
                    for (int j=zeroIdx+1; j<nums.size(); j++) {
                        if (nums[j]==0) {
                            zeroIdx = j;
                            break;
                        }
                    }
                }
            }
        }
    }
};