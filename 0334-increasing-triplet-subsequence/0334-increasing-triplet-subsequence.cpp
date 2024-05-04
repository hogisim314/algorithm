class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int ft=INT_MAX, sc=INT_MAX;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i]<=ft) {
                ft = nums[i];
            }
            else if (nums[i]<=sc) {
                sc = nums[i];
            }
            else {
                return true;
            }
        }
        return false;
    }
};