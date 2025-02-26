class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
         int n = s.length();
    int count = 0;
    
    auto countWithConstraint = [&](char target) {
        int left = 0, zeroCount = 0, oneCount = 0, total = 0;
        
        for (int right = 0; right < n; right++) {
            if (s[right] == '0') zeroCount++;
            else oneCount++;

            // Maintain the window where min(0s, 1s) <= k
            while (zeroCount > k && oneCount > k) {
                if (s[left] == '0') zeroCount--;
                else oneCount--;
                left++;
            }

            // Add valid substrings
            total += (right - left + 1);
        }
        
        return total;
    };

    return countWithConstraint('0'); 
    }
};