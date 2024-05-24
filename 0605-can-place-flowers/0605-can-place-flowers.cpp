class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for (int i=0; i<flowerbed.size(); i++) {
            if (flowerbed[i]==1) {
                i++;
            }
            else if (n>0 && ((i+1<flowerbed.size() && flowerbed[i]==0 && flowerbed[i+1]==0)|| (i==flowerbed.size()-1 && flowerbed[i]==0))) {
                flowerbed[i] = 1;
                i++;
                n--;
            } 
        }

        for (int i=0; i<flowerbed.size(); i++) {
            cout<<flowerbed[i]<<' ';
        }

        if (n>0) {
            return false;
        }
        return true;
    }
};