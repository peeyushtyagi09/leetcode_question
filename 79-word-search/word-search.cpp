class Solution {
public:
bool dfs(vector<vector<char>> &board, int row, int col, string& word, int index){
    if (index == word.size()) return true;
    if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[index]){
        return false;
    }
    char temp = board[row][col];
    board[row][col] = '#';

    bool found = dfs(board, row + 1, col, word, index + 1) ||
                dfs(board, row - 1, col, word, index + 1) ||
                dfs(board, row, col + 1, word, index + 1)||
                dfs(board, row, col - 1, word, index + 1);
                board[row][col] = temp;
                return found;
}
    bool exist(vector<vector<char>>& board, string word) {
        // Number of rows
        int m = board.size();
        // Number of cols
        int n = board[0].size();
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (board[i][j] == word[0] && dfs(board, i, j, word, 0))
                return true;
            }
        }  
        return false;
    }
};