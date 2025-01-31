class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN) return 0;  // Handle the edge case for INT_MIN
        
        int result = 0;
        int sign = (x < 0) ? -1 : 1;
        x = abs(x);
        
        while (x > 0) {
            int rem = x % 10;
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && rem > 7)) {
                return 0;  // Handle overflow case
            }
            result = result * 10 + rem;
            x /= 10;
        }
        
        return sign * result;
    }
};
