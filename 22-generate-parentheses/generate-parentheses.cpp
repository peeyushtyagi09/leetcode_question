class Solution {
public:
void generatePar(string current, int open, int close, int n,  vector<string> &result){
    if(current.length() == 2 * n){
        result.push_back(current);
        return;
    }
    if (open < n){
        generatePar(current + '(' , open + 1, close,n,  result);
    }
    if (close < open){
        generatePar(current + ')' , open, close + 1,n, result);
    }
}
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generatePar("", 0, 0,n, result);
        return result;
    }
};