class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;

        for (char task : tasks){
            freq[task]++;
        }

        priority_queue<int> maxHeap;
        for (auto& it : freq){
            maxHeap.push(it.second);
        }

        int time = 0;

        while(!maxHeap.empty()){
            vector<int> temp;
            int cycle = n + 1;

            while(cycle > 0 && !maxHeap.empty()){
                int top = maxHeap.top(); maxHeap.pop();
                if(top > 1) temp.push_back(top - 1);
                cycle--;
                time++;
            }

            for(int remaining : temp){
                maxHeap.push(remaining);
            }

            if(!maxHeap.empty()){
                time += cycle;  
            }
        }

        return time;  
    }
};
