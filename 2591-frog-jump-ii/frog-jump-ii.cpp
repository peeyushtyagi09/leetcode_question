class Solution {
public:
    int maxJump(vector<int>& stones) {
        int maxJump = 0;
        int n = stones.size();
        for (int i = 0; i + 2 < n; ++i){
            maxJump = max(maxJump, stones[i + 2] - stones[i]);
        }
        // Also consider the first and last Jumps
        maxJump = max(maxJump, stones[1] - stones[0]);
        maxJump = max(maxJump, stones[n - 1] - stones[n - 2]);
        return maxJump;
    }
};