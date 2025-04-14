class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
         int n = score.size();
    priority_queue<pair<int, int>> maxHeap;

    // Push (score, index) into maxHeap
    for (int i = 0; i < n; ++i) {
        maxHeap.push({score[i], i});
    }

    vector<string> result(n);
    int rank = 1;

    while (!maxHeap.empty()) {
        auto [val, idx] = maxHeap.top();
        maxHeap.pop();

        if (rank == 1)
            result[idx] = "Gold Medal";
        else if (rank == 2)
            result[idx] = "Silver Medal";
        else if (rank == 3)
            result[idx] = "Bronze Medal";
        else
            result[idx] = to_string(rank);

        ++rank;
    }

    return result;
    }
};