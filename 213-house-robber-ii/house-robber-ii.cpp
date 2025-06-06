class Solution {
public:
  int robLinear(vector<int>& nums, int start, int end) {
        int prev1 = 0, prev2 = 0;
        for (int i = start; i <= end; ++i) {
            int take = nums[i] + prev2;
            int skip = prev1;
            int curr = max(take, skip);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {

         int n = nums.size();
         if (n == 1) return nums[0];

         int option1 = robLinear(nums, 0, n - 2);
         int option2 = robLinear(nums, 1, n - 1);
         return max(option1, option2);
    }
    
};