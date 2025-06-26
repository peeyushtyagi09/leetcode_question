class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int countof5 = 0;
        int countof10 = 0;
        for (int num : bills){
            if (num == 5){
                countof5++;
            }
            else if(num == 10){
                if (countof5 >= 1){
                    countof5--;
                    countof10++;
                }else{
                    return false;
                }
            }
            else if (num == 20){
                if(countof10 >= 1 && countof5 >= 1){
                    countof10--;
                    countof5 -= 1;
                }
                else if (countof5 >= 3){
                    countof5 -= 3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};