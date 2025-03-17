class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // unordered_map<int, int> freq;
        // for (int num : nums){
        //     freq[num]++;
        // }
        // for (auto entry : freq){
        //     if (entry.second > 1){
        //         return true;
        //     }
        // }
        // return false;

        // optimal solution of that code 
        unordered_set<int>seen;
        for (int num : nums){
            if (seen.count(num)) return true;
            seen.insert(num);
        }
        return false;
    }
};