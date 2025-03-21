class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int smallest = INT_MAX;
        for (int i = 0; i < n; i++){
            if (nums[i] < smallest){
                smallest = nums[i];
            }
        }
        return smallest;
    }
};