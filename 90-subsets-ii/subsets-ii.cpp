class Solution {
public:
void findSubset(vector<int> &current, int start, vector<int> &nums, vector<vector<int>> &result){
    result.push_back(current);
    for (int i = start; i < nums.size(); i++){ 
        if (i > start && nums[i] == nums[i - 1]) continue;
        current.push_back(nums[i]);
        findSubset(current, i + 1, nums,  result);
        current.pop_back();

    }
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int> current;

        sort(nums.begin(), nums.end());
        findSubset(current, 0, nums, result);
        return result;
    }
};