class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
          int n = matrix.size();

        // Validate input
        if (n == 0 || matrix[0].size() != n) {
            cerr << "Invalid input: Matrix must be non-empty and square." << endl;
            return 0;
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                int down = matrix[i + 1][j];
                int downLeft = (j > 0) ? matrix[i + 1][j - 1] : INT_MAX;
                int downRight = (j < n - 1) ? matrix[i + 1][j + 1] : INT_MAX;
                matrix[i][j] += min({down, downLeft, downRight});
            }
        }

        return *min_element(matrix[0].begin(), matrix[0].end());
    }
};