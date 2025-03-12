class Solution {
public:
    void findCombination(int index, int target, vector<int>& candidates, vector<vector<int>>& result, vector<int>& current) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        
        for (int i = index; i < candidates.size(); i++) {
            if (candidates[i] > target) break;  
            current.push_back(candidates[i]);
            findCombination(i, target - candidates[i], candidates, result, current);
            current.pop_back();  
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        sort(candidates.begin(), candidates.end()); 
        findCombination(0, target, candidates, result, current);
        return result;
    }
};
