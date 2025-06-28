class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // If you want to insert at the end
        intervals.push_back(newInterval);
        // If You want to insert at the start
        // intervals.insert(intervals.begin(), newInterval);
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
            return a[0] < b[0];
        });
        vector<vector<int>> result;
        for(auto interval : intervals){
            
            if(result.empty() || result.back()[1] < interval[0]){
                result.push_back(interval);
            }
            else{
                result.back()[1] = max(result.back()[1], interval[1]);
            }
        }
        return result;
    }
};