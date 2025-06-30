class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        // if (n <= 2){
        //     return nums;
        // } 
        unordered_map<int, int> freq;
        for (int num : nums){
            freq[num]++;
        }
        vector<int> result;
        for(auto i : freq){
            if(i.second > (n/3)){
                result.push_back(i.first);
            }
        }
        return result;
    }
};