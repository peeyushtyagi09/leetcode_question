class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        int best_buy = prices[0];
        int maxi = INT_MIN;
        for (int i = 1; i < prices.size(); i++){
            if (prices[i] > best_buy){
                maxi = max(maxi, prices[i] - best_buy);
            }
            best_buy = min(best_buy, prices[i]);
        }
        return (maxi == INT_MIN) ? 0 : maxi;
    }
};