class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxi = nums[0];
        for (int i = 1; i < nums.size(); i++){
            if (i > maxi) return false;
            maxi = max(maxi, i + nums[i]);
        }
        return true;
    }
};