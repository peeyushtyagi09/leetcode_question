class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int>pq;
        for (int i : nums){
            pq.push(i);
        }
        while(k > 1){
            pq.pop();
            k--;
        }
        return pq.top();
    }
};