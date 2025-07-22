class Solution {
public:
    int reverse(int num) {
        int ans = 0;
        while(num != 0){
            int digit = num % 10;
            num = num / 10;

            if (ans > 214748364 || (ans == 214748364  && digit > 7)) return 0;
             if (ans < -214748364 || (ans == -214748364  && digit < -8)) return 0;

             ans = ans * 10 + digit;
        }
        return ans;
    }
};