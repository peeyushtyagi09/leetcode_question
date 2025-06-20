// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//     vector<int> dp(n, 1);
//     for (int i = 1; i < m; i++){
//         for (int j = 1; j < n; j++){
//             dp[j] = dp[j] + dp[j - 1];
//         }
//     }
//     return dp[n - 1];
//     }
// };

// secound solution 
class Solution  {
    public:
        int uniquePaths(int m, int n){
           long long res = 1;
           int N = m + n - 2;
           int r = min(m - 1, n - 1);
           for (int i = 1; i <= r; i++){
            res = res * (N - r + i) / i;
           }
           return (int)res;
        }
};