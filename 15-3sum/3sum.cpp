class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        const int n = nums.size();
        
        for (int i = 0; i < n - 2; i++){

            // === Skip duplicates ====
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            if (nums[i] > 0) break;
            int j = i + 1, k = n - 1;

            while(j < k){
                const long long sum = 1LL*nums[i] + nums[j] + nums[k];

                if (sum == 0){
                    ans.push_back({nums[i], nums[j], nums[k]});

                    while(j < k && nums[j] == nums[j + 1]) ++j;

                    while(j < k && nums[k] == nums[k - 1]) --k;

                    ++j;
                    --k;
                }else if(sum < 0){
                    ++j;
                }else{
                    --k;
                }
            }
        }
        return ans;
    }
};