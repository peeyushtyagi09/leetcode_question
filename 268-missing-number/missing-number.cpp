class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> number;
        for (int num : nums){
            number.insert(num);
        }
        for (int i = 0; i < nums.size(); i++){
            if (number.find(i) == number.end()){
                return i;
            }
        }
        return nums.size();
    }
};