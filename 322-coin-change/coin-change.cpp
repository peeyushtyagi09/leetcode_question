class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // this sis the greedy code but is not completely correct 


        // sort(coins.begin(), coins.end());
        // int count = 0;
        // int i = coins.size() - 1;
        // while(amount > 0 && i >= 0){
        //     if(amount >= coins[i]){
        //         int num = amount / coins[i];
        //         count += num;
        //         amount -= coins[i] * num;
        //     }else{
        //         i--;
        //     }
        // }
        // return amount == 0 ? count : -1;

        // correct code using DP
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 0; i <= amount; ++i){
            for (int coin : coins){
                if (i >= coin){
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};