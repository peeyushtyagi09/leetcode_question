class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // that code is correct but it has two mistake
        // firstmistake is that -> Note that you don't need to modify intervals in-place. You can make a new array and return it.
        // secound mistake is that it has high time complexity O(n log n)

        // // If you want to insert at the end
        // intervals.push_back(newInterval);
        // // If You want to insert at the start
        // // intervals.insert(intervals.begin(), newInterval);
        // sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
        //     return a[0] < b[0];
        // });
        // vector<vector<int>> result;
        // for(auto interval : intervals){
            
        //     if(result.empty() || result.back()[1] < interval[0]){
        //         result.push_back(interval);
        //     }
        //     else{
        //         result.back()[1] = max(result.back()[1], interval[1]);
        //     }
        // }
        // return result;

        vector<vector<int>> res;
        int i = 0, n = intervals.size();

        while(i < n && intervals[i][1] < newInterval[0]){
            res.push_back(intervals[i++]);
        }

        while(i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            ++i;
        }
        res.push_back(newInterval);

        while(i < n) res.push_back(intervals[i++]);

        return res;
    }
};