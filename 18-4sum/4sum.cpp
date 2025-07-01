class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        const int n = nums.size();
        vector<vector<int>> ans;

        for (int i = 0; i < n - 3; ++i){
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // Optional purning
            long long min1 = 1LL*nums[i]  + nums[i + 1] + nums[i + 2] + nums[i + 3];
            if(min1 > target) break;
            long long max1 = 1LL*nums[i] + nums[n - 1] + nums[n - 2] + nums[n - 3];
            if (max1 < target) continue;

            for(int j = i + 1; j < n - 2; j++){
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;


                long long min2 = 1LL*nums[i]+ nums[j] + nums[j + 1] + nums[j + 2];
                if (min2 > target) break;
                long long max2 = 1LL*nums[i] + nums[j] + nums[n - 1] + nums[n - 2];
                if (max2 < target) continue;

                int p = j + 1, q = n - 1;

                while(p < q){
                    long long sum = 1LL*nums[i] + nums[j] + nums[p] + nums[q];

                    if (sum == target){
                        ans.push_back({nums[i], nums[j], nums[p], nums[q]});

                        while(p < q && nums[p] == nums[p + 1]) ++p;
                        while(p < q && nums[q] == nums[q - 1]) --q;
                        ++p;
                        --q;
                    }else if (sum < target){
                        ++p;
                    }else{
                        --q;
                    }
                }
            }
        }
        return ans;
    }
};