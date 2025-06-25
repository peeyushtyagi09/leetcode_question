class Solution {
public:
    int countPartitions(vector<int>& nums) {
       int count = 0;
        long long totalSum = 0;
        for (int num : nums) {
            totalSum += num; // Compute total sum safely
        }
        long long leftSum = 0;
        for (int i = 0; i < nums.size() - 1; i++) { // Stop at n-2
            leftSum += nums[i];
            long long rightSum = totalSum - leftSum;
            if ((leftSum - rightSum) % 2 == 0) { // Check difference directly
                count++;
            }
        }
        return count;
    }
};