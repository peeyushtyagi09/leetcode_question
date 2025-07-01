class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        const int n = nums.size();
        
        for (int i = 0; i < n - 2; ++i){

            // ==== Skip Duplicates === 
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // Only need to search if current value can still reach 0
            if (nums[i] > 0) break;

            //  === Two Pointer === 
            int j = i + 1, k = n - 1;

            while(j < k) {
                const long long sum = 1LL*nums[i] + nums[j] + nums[k];

                if (sum == 0){
                    // Found a triplet
                    ans.push_back({nums[i], nums[j], nums[k]});

                    // ==== Skip duplicates for the secound element ==== 
                    while (j < k && nums[j] == nums[j + 1]) ++j;

                    // ==== Skip duplicates for the third element ==== 
                    while (j < k && nums[k] == nums[k - 1]) --k;

                    ++j;
                    --k;
                }
                else if (sum < 0){
                    // need a larger sum
                    ++j;
                }else{
                    // sum > 0 -> need a smaller sum
                    --k;
                }
            }
        }
        return ans;
    }
};