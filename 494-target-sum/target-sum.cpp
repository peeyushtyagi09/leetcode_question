class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
       int totalSum  = accumulate(nums.begin(), nums.end(), 0);

    // If impossible
    if ((target + totalSum) % 2 != 0 || abs(target) > totalSum) return 0;

    int subsetSum = (target + totalSum) / 2;

    vector<int> dp(subsetSum + 1, 0);
    dp[0] = 1;

    for (int num : nums){
        for (int j = subsetSum; j >= num; j--){
            dp[j] += dp[j - num];
        }
    }
    return dp[subsetSum];
    }
};