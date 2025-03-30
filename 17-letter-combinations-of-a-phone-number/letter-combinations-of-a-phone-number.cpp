class Solution {
public:
    vector<string> result;
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
  void backtrack(string &digits, int index, string current){
    if (index == digits.size()){
        result.push_back(current);
        return;
    }

    string letters = mapping[digits[index] - '0'];

    for (char letter : letters){
        backtrack(digits, index + 1, current + letter);
    }
  }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        backtrack(digits, 0, "");
        return result;
    }
};