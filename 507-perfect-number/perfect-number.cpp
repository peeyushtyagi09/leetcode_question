class Solution {
public:
    bool checkPerfectNumber(int num) {
        int temp = num;
        int sum = 0;
        temp = temp/2;
        while(temp > 0){
            if (num % temp == 0){
                sum += temp;
            }
            temp--;
        }
        if (sum == num){
            return true;
        }else{
            return false;
        }
    }
};