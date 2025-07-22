class Solution {
public:
    bool isPalindrome(int num) {
        if (num < 0) return false;
        int Temp = num;
        long long int ans = 0 ;
        while (Temp != 0){
            long long int digit =  Temp % 10;
            ans = ans * 10 + digit;
            Temp /= 10;
        }
        if(num == ans) return true;
        else return false;
    }
};