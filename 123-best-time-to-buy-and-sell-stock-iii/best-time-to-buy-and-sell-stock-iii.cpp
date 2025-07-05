class Solution {
public:
    int maxProfit(vector<int>& prices) {
          int buy1 = INT_MIN, sell1 = 0;
        int buy2 = INT_MIN, sell2 = 0;

        for (int price : prices) {
            buy1  = std::max(buy1, -price);
            sell1 = std::max(sell1, buy1 + price);
            buy2  = std::max(buy2, sell1 - price);
            sell2 = std::max(sell2, buy2 + price);
        }

        return sell2;
    }
};