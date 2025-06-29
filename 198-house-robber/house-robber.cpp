class Solution {
public:
    int rob(vector<int>& nums) {
        // int prev2 = 0, prev1 = 0;
        // for (int num : nums){
        //     int temp = max(prev1, prev2 + num);
        //     prev2 = prev1;
        //     prev1  = temp;
        // }
        // return prev1;
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        int prev1 = nums[0];
        int prev2 = max(nums[0], nums[1]);
        for (int i = 2; i < n; ++i){
            int curr = max(prev2, prev1 + nums[i]);
            prev1 = prev2;
            prev2 = curr;
        }
        return prev2;
    }
};