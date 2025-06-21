class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    vector<vector<int>> dp(m, vector<int>(n, 0));

    // Initialize starting point
    if (obstacleGrid[0][0] == 1) return 0;
    dp[0][0] = 1;

    // Fill first column
    for (int i = 1; i < m; ++i)
        dp[i][0] = (obstacleGrid[i][0] == 0 && dp[i-1][0] == 1) ? 1 : 0;

    // Fill first row
    for (int j = 1; j < n; ++j)
        dp[0][j] = (obstacleGrid[0][j] == 0 && dp[0][j-1] == 1) ? 1 : 0;

    // Fill rest of the dp table
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (obstacleGrid[i][j] == 0)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            // else it remains 0 (default)
        }
    }

    return dp[m-1][n-1];
    }
};