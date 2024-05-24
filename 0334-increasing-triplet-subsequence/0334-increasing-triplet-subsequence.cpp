class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int min1=INT_MAX, min2 = INT_MAX;

        for (int i=0; i<nums.size(); i++) {
            if (nums[i]<=min1) {
                min1 = nums[i];
            }
            else if (nums[i]<=min2) {
                min2 = nums[i];
            }
            else if (nums[i]>min1 && nums[i]>min2) {
                return true;
            }
        }
        return false;
    }
};