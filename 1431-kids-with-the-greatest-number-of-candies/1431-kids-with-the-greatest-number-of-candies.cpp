#include <algorithm>
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxx = 0;
        vector<bool> res;
        for (int i=0; i<candies.size(); i++) {
            maxx = max(maxx, candies[i]);
        }
        for (int i=0; i<candies.size(); i++) {
            if (candies[i]+extraCandies>=maxx) {
                res.push_back(true);
            }
            else {
                res.push_back(false);
            }
        }
        return res;
    }
};