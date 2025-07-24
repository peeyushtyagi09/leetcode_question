class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int>freq;
        for (int num : nums){
            freq[num]++;
        }
        int maxFreq = 0;
        for (auto& pair : freq){
            maxFreq = max(maxFreq, pair.second);
        }

        int count = 0;
        for (auto& pair : freq){
            if(pair.second == maxFreq){
                count += pair.second;
            }
        }
        return count;
    }
};