class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        int one = 2;
        int two = 1;
        int allways = 0;

        for (int i = 3; i <= n; ++i){
            allways = one + two;
            two = one;
            one = allways;
        }
        return allways;
    }
};