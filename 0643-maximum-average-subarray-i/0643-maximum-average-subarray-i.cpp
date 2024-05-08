class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum=0;
        double aver=0;
        double ans=-999999999;
        for (int i=0; i<k; i++) {
            sum+=nums[i];
        }
        ans = max(ans, sum);
        for (int i=0; i<nums.size()-k; i++) {
            sum -= nums[i];
            sum += nums[i+k];
            ans = max(ans, sum);
        }
        aver = ans / k;
        return aver;
    }
};