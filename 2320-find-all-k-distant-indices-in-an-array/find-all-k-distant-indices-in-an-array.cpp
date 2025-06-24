class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> result;
        int n = nums.size();

        // Step1 : Collect all indices where nums[i] == key
        vector<int> KeyIndices;
        for (int i = 0; i < n; i++){
            if (nums[i] == key){
                KeyIndices.push_back(i);
            }
        }

        // Step2: Mark Valid indicies in a boolean array
        vector<bool> isValid(n, false);
        for (int idx : KeyIndices){
            int left = max(0, idx - k);
            int right = min(n - 1, idx + k);
            for (int i = left; i <= right; ++i){
                isValid[i] = true;
            }
        }

        // Step3: Collect all marked indices
        for (int i = 0; i < n; ++i){
            if (isValid[i]){
                result.push_back(i);
            }
        }
        return result;
    }
};