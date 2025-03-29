class Solution {
public:
void genaratesubsets(vector<int>&current, int start, vector<int>&n, vector<vector<int>>&result){
    result.push_back(current);
    for (int i = start; i < n.size(); i++){
        current.push_back(n[i]);
        genaratesubsets(current, i + 1, n, result);
        current.pop_back();
    }
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        genaratesubsets(current, 0, nums, result);
        return result;
    }
};