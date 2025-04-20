class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // brute force approach using unordered_map;
        // unordered_map<int, int> freq;
        // for(int num : nums){
        //     freq[num]++;
        // }

        // vector<pair<int, int>> freqVec(freq.begin(), freq.end());
        // sort(freqVec.begin(), freqVec.end(), [](pair<int, int>& a, pair<int, int>& b){
        //     return a.second > b.second;
        // });
        // vector<int> result;
        // for (int i = 0; i < k; i++){
        //     result.push_back(freqVec[i].first);
        // }
        // return result;
        unordered_map<int, int> freq;
        for(int num : nums){
            freq[num]++;
        }
        vector<pair<int, int>> freqVec(freq.begin(), freq.end());
        sort(freqVec.begin(), freqVec.end(), [](pair<int, int>&a, pair<int, int>& b){
            return a.second > b.second;
        });
        vector<int> result;
        for (int i = 0; i < k; i++){
            result.push_back(freqVec[i].first);
        }
        return result;
    }
};