class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxx=0;

        int l=0; 
        int r = height.size()-1;

        maxx = (r-l) * min(height[r], height[l]);

        while(l<r) {
            if (min(height[l+1], height[r])>min(height[l], height[r-1])) {
                l++;
            }
            else r--;

            maxx = max(maxx,(r-l) * min(height[r], height[l]));
        }
        return maxx;
    }
};