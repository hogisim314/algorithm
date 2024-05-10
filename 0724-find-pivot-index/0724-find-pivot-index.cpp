class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int partialSum[10005];
        int tempSum=0;
        int ans=-1;
        int n = nums.size()-1;
        if (n==0) {
            return -1;
        }
        for (int i=0; i<nums.size(); i++) {
            tempSum += nums[i];
            partialSum[i] = tempSum;
        }
        for (int i=0; i<nums.size(); i++) {
            if (i==0) {
                if (partialSum[n] - partialSum[0] == 0) {
                    ans = 0;
                    break;
                }
                continue;
            }
            if (i==n) {
                if (partialSum[n-1] == 0) {
                    ans = n;
                    break;
                }
            }
            if (partialSum[i-1] == partialSum[n]-partialSum[i]) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};