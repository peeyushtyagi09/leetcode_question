class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
          int m = matrix.size();        // number of rows
        int n = matrix[0].size();     // number of columns

        bool firstRow = false;
        bool firstCol = false;

        // Step 1: Check if first row has any zeros
        for (int j = 0; j < n; ++j) {
            if (matrix[0][j] == 0) {
                firstRow = true;
                break;
            }
        }

        // Step 2: Check if first column has any zeros
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) {
                firstCol = true;
                break;
            }
        }

        // Step 3: Use first row and column as markers
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;  // mark corresponding row
                    matrix[0][j] = 0;  // mark corresponding column
                }
            }
        }

        // Step 4: Set matrix[i][j] to 0 if its row or col is marked
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Step 5: Zero the first row if needed
        if (firstRow) {
            for (int j = 0; j < n; ++j) {
                matrix[0][j] = 0;
            }
        }

        // Step 6: Zero the first column if needed
        if (firstCol) {
            for (int i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};