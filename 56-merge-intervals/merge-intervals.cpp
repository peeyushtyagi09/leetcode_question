class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
            // vector<vector<int>> result;

            // sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
            //     return a[0] < b[0];
            // });

            // for(auto interval : intervals){
            //     if(result.empty() || result.back()[1] < interval[0]){
            //         result.push_back(interval);
            //     }else{
            //         result.back()[1] = max(result.back()[1], interval[1]);
            //     }
            // }
            // return result;
            vector<vector<int>> result;
            sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
                return a[0] < b[0];
            });
            for (auto interval : intervals){
                if (result.empty() || result.back()[1] < interval[0]){
                    result.push_back(interval);
                }else{
                    result.back()[1] = max(result.back()[1], interval[1]);
                }
            }
            return result;
    }
};