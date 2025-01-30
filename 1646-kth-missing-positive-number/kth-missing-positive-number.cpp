class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
         int missing = 0, count = 0, idx = 0;
         for (int num = 1; ; num++){
            if (idx < arr.size() && arr[idx] == num){
                idx++;
            }else{
                count++;
                if (count == k) return num;
            }
         }
         return -1;
    }
};