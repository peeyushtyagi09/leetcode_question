class Solution {
public:
    bool checkPerfectNumber(int num) { 
        
        int count = 1;
        long long int ans = 0;
        while(count != (num / 2) + 1){
            if (num % count == 0){
                ans += count;
            }
            count++;
        }
        if (num == ans) return true;
        else return false;
    }
};