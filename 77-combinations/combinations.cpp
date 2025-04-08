class Solution {
public:
void solve(vector<int>&current, int start, int n, int k, vector<vector<int>>&result){
    if (k == 0){
        result.push_back(current);
        return;
    }
    for(int i = start; i <= n; i++){
        current.push_back(i);
        solve(current, i + 1, n, k - 1, result);
        current.pop_back();
    }
}
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> current;
        solve(current, 1, n, k, result);
        return result;

    }
};