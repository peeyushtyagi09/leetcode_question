class Solution {
public:
    int maximumUnits(vector<vector<int>>& arr, int truckSize) { 
        sort(arr.begin(), arr.end(), [](const vector<int>& a, const vector<int> & b) {
            return a[1] > b[1];
        });
        long long ans = 0;
        int boxesUsed = 0;
         for (const auto& box : arr) {
            int numBoxes = box[0];
            int unitsPerBox = box[1];

            if(boxesUsed + numBoxes <= truckSize){
                ans += (long long)numBoxes * unitsPerBox;
                boxesUsed += numBoxes;
            }

            else{
                int remainingCapacity = truckSize - boxesUsed;
                ans += (long long)remainingCapacity * unitsPerBox;
                break;
            }
         }
         return ans;
    }
};