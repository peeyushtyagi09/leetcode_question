class Solution {
public:
    string addStrings(string num1, string num2) {
          int i = num1.size() - 1;  // Pointer for num1
        int j = num2.size() - 1;  // Pointer for num2
        int carry = 0;
        string result = "";

        // Process both strings from right to left
        while (i >= 0 || j >= 0 || carry != 0) {
            int d1 = (i >= 0) ? num1[i] - '0' : 0;  // Get digit from num1 or 0
            int d2 = (j >= 0) ? num2[j] - '0' : 0;  // Get digit from num2 or 0
            int sum = d1 + d2 + carry;

            carry = sum / 10;  // Carry for next step
            result += (sum % 10) + '0';  // Add current digit to result
            i--;
            j--;
        }

        // Reverse the result to get the correct order
        reverse(result.begin(), result.end());
        return result;
    }
};