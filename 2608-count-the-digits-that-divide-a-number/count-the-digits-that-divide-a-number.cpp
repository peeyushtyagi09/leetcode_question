class Solution {
public:
    int countDigits(int num) {
        int Temp = num;
        if (Temp < 10) return 1;
        int count = 0;
        while(Temp > 0){
            int digit = Temp % 10;
            if (num % digit == 0){
                count++;
            }

            Temp /= 10;
        }
        return count;
    }
};