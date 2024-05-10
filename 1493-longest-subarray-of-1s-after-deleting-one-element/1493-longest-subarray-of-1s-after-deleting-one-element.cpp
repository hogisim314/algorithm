class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l=0;
        int i=0;
        int life = 1;
        int maxx = 0;
        while(true) {
            if (i==nums.size()) {
                maxx = max(maxx, i-l-1);
                break;
            }
            if (nums[i] == 0) {
                life --;
                if (life ==0) {
                    i++;
                }
                else if (life<0) {
                    maxx = max(maxx, i-l-1);
                    while(true) {
                        if (l==nums.size()) {
                            break;
                        }
                        if (nums[l]==1) {
                            l++;
                        }
                        else if (nums[l] == 0) {
                            life = 0;
                            l++;
                            i++;
                            break;
                        }
                    }
                }
            }
            else if (nums[i] == 1) {
                i++;
            }
        }
        return maxx;
    }
};