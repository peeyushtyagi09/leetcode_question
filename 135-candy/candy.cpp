class Solution {
public:
    int candy(vector<int>& ratings) {
        // Brute force approach of that question 
        // Steps : 
        // step 1 : first we create teo array left[n] and right[n] and compare first with left and right
        // step 2 : we create sum and add max between left and right and then we return it
        // Let start the code -> 
        int n = ratings.size();
        int left[n], right[n];
        left[0] = 1, right[n - 1] = 1;
        for (int i = 1; i < n; i++){
            if(ratings[i] > ratings[i - 1]){
                left[i] = left[i - 1] + 1;
            }else{
                left[i] = 1;
            }
        }
        for (int i = n - 2; i >= 0; i--){
            if(ratings[i] > ratings[i + 1]){
                right[i] = right[i + 1] + 1;
            }else{
                right[i] = 1;
            }
        }
        long long sum = 0;
        for (int i = 0; i < n; i++){
            sum += max(left[i], right[i]);
        }
        return sum;
    }
};