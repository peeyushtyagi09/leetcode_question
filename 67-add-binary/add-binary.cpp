class Solution {
public:
    string addBinary(string a, string b) {
          int i = a.size() - 1; // Pointer for string a
    int j = b.size() - 1; // Pointer for string b
    int carry = 0;        // Initial carry is 0
    string result = "";   // Store result

    // Traverse both strings from the end
    while (i >= 0 || j >= 0 || carry > 0) {
        int sum = carry; // Start with carry value

        // Add a[i] if available
        if (i >= 0) {
            sum += a[i] - '0'; // Convert char to int
            i--;
        }

        // Add b[j] if available
        if (j >= 0) {
            sum += b[j] - '0';
            j--;
        }

        // Append the binary result (sum % 2) to the final result
        result += (sum % 2) + '0';

        // Update carry for next position
        carry = sum / 2;
    }

    // Reverse the result to get the final binary sum
    reverse(result.begin(), result.end());
    return result;
    }
};