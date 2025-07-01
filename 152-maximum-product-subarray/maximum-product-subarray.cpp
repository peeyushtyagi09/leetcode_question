class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // that is the brute force approach that code file you TLE 
        // The time complexity of this code is 0(n)3
        // int max_product = INT_MIN;
        // int n = nums.size();

        // for(int i = 0; i < n; i++){
        //     for(int j = i; j < n; j++){
        //         int product = 1;
        //         for(int k = i; k <= j; k++){
        //             product = product * nums[k];
        //         }
        //         max_product = max(max_product, product);
        //     }
        // }
        // return max_product;

        // Optimized this up to O(n)2

        int max_product = INT_MIN;
        int n = nums.size();

        for (int i = 0; i < n; i++){
            int product = 1;
            for (int j = i; j < n; j++){
                product = product * nums[j];

                max_product = max(max_product, product);
            }
        }
        return max_product;
    }
};