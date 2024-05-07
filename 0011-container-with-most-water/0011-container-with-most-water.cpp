class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxx=0;
        int l=0;
        int amount=0;
        int r = height.size()-1;
        while(true) {
            if (l==r) {
                break;
            }
            amount = (r-l)*min(height[l], height[r]);
            maxx = max(maxx, amount);
            if (height[l]>height[r]) {
                r--;
            }
            else l++;
        }
        return maxx;
    }
};