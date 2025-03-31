class Solution {
public:
void backtrack(string &num, int idx, long prevOperand, long currSum, string path, int target, vector<string> &res){
     // \U0001f3af Base Case: If we've reached the end of the string
        if (idx == num.size()) {
            if (currSum == target) {
                res.push_back(path);  // ✅ Add valid path to result
            }
            return;
        }

        // \U0001f504 Explore all possible substrings starting from idx
        for (int i = idx; i < num.size(); i++) {
            // ⚠️ Skip leading zeros (e.g., "05" is invalid)
            if (i != idx && num[idx] == '0') break;

            // \U0001f4da Extract the substring and convert to number
            string currStr = num.substr(idx, i - idx + 1);
            long currNum = stol(currStr);

            // \U0001f3af First operand (initial number, no operator needed)
            if (idx == 0) {
                backtrack(num, i + 1, currNum, currNum, path + currStr, target, res);
            } else {
                // ➕ Add '+'
                backtrack(num, i + 1, currNum, currSum + currNum, path + "+" + currStr, target, res);

                // ➖ Add '-'
                backtrack(num, i + 1, -currNum, currSum - currNum, path + "-" + currStr, target, res);

                // ✖️ Add '*'
                backtrack(num, i + 1, prevOperand * currNum, currSum - prevOperand + (prevOperand * currNum), path + "*" + currStr, target, res);
            }
        }
}
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        if (num.empty()) return res;
        backtrack(num, 0, 0, 0, "", target, res);
        return res;
    }
};