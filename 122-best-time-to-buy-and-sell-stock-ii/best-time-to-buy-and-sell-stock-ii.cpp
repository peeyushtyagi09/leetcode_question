class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // first using Greedy approach 
        // int profit = 0;
        // for (int i = 1; i < prices.size(); i++){
        //     if (prices[i] > prices[i - 1]){
        //         profit += prices[i] - prices[i - 1];
        //     }
        // }
        // return profit;

        // now using Dp 
        int flat = 0;
        int hold = -prices[0];
        for (int i = 1; i < prices.size(); i++){
            int newflat = max(flat, hold + prices[i]);
            int newhold = max(hold, flat - prices[i]);
            flat = newflat;
            hold = newhold;
        }
        return flat;
    }
};