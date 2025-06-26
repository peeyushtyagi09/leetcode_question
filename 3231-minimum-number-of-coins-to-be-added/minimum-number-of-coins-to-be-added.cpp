class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(), coins.end());
        
        long long maxCovered = 0;
        int addedCoins = 0;
        int i = 0;

        while(maxCovered < target) {
            if (i < coins.size() && coins[i] <= maxCovered + 1){
                maxCovered += coins[i];
                i++;
            }else{
                maxCovered += maxCovered + 1;
                addedCoins++;
            }
        }
        return addedCoins;
    }
};