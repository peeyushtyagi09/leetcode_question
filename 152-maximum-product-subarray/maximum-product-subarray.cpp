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

        // int max_product = INT_MIN;
        // int n = nums.size();

        // for (int i = 0; i < n; i++){
        //     int product = 1;
        //     for (int j = i; j < n; j++){
        //         product = product * nums[j];

        //         max_product = max(max_product, product);
        //     }
        // }
        // return max_product;
        // that code is run but i am not happy with that code we have to 
        // Optimized this code 

        // Optimal solution using Dp
        int n = nums.size();
        int maxSoFar = nums[0];
        int maxProd = nums[0];
        int minProd = nums[0];

        for(int i = 1; i < n; i++){
            int curr = nums[i];

            if (curr < 0){
                swap(maxProd, minProd);
            }
            maxProd = max(curr, curr * maxProd);
            minProd = min(curr, curr * minProd);

            maxSoFar = max(maxSoFar, maxProd);
        }
        return maxSoFar;
    }
};