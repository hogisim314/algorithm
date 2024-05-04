class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int mul=1;
        int zeroExist=0;
        vector<int> ans;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i]==0) {
                zeroExist++;
                continue;
            }
            mul*=nums[i];
        }
        for (int i=0; i<nums.size(); i++) {
            if (zeroExist>=2) {
                ans.push_back(0);
            }
            else if (zeroExist==1) {
                if (nums[i]!=0) {
                    ans.push_back(0);
                }
                else {
                    ans.push_back(mul);
                }
            }
            else {
                ans.push_back(mul/nums[i]);
            }
        }
        return ans;
    }
};