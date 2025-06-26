class Solution {
public:
    bool checkValidString(string s) {
          int left = 0; // Minimum open parentheses count
        int left_max = 0; // Maximum open parentheses count
        int star = 0; // Keep star for consistency with your style
        for (char par : s) {
            if (par == '(') {
                left++;
                left_max++;
            }
            else if (par == ')') {
                left--;
                left_max--;
                if (left_max < 0) return false; // Too many )
                if (left < 0) left = 0; // * can be empty
            }
            else if (par == '*') {
                star++;
                left--; // * can be )
                left_max++; // * can be (
                if (left < 0) left = 0; // * can be empty
            }
        }
        if (left > 0) return false; // Unmatched ( remaining
        return true;
    }
};