class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) {
         unordered_map<int, int> freqMap; // Map to store the frequency of each number

        // Calculate frequencies of each number
        for (int num : arr) {
            freqMap[num]++;
        }

        int first = -1;
        int second = -1;

        // Find the first occurrence and calculate the last occurrence
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == target) {
                first = i; // First occurrence
                second = first + freqMap[target] - 1; // Last occurrence
                break; // No need to continue after finding the first occurrence
            }
        }

        return {first, second};
    }
};