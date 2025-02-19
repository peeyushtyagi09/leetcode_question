class Solution {
public:
    int calPoints(vector<string>& ops) {
        // that is the Brute approach of thiis question (vector)

        // vector<int>record;
        // for (string st : ops){
        //     if (st == "C"){
        //         record.pop_back();
        //     }else if (st == "D"){
        //         record.push_back(2 * record.back());
        //     }else if (st == "+"){
        //         int n = record.size();
        //         record.push_back(record[n - 1] + record[n - 2]);
        //     }else{
        //         record.push_back(stoi(st));
        //     }
        // }
        // int sum = 0;
        // for(int num : record){
        //     sum += num;
        // }
        // return sum;

//Complexity Analysis
// Time Complexity:  O(n)
// Each operation is processed once, and push_back/pop_back runs in  O(1).
// Space Complexity:  O(n)
// We store all valid scores in a vector.


// The optimal approach of that question is using stack
//A stack is more efficient than a vector since it supports push and pop in O(1).
//The logic remains the same, but we use stack<int> instead.
    stack<int> record;
    int sum = 0;
    for (string op : ops){
        if (op == "C"){
            sum -= record.top();
            record.pop();
        }else if (op == "D"){
            int last = 2 * record.top();
            sum += last;
            record.push(last);
        }else if (op == "+"){
            int top1 = record.top(); record.pop();
            int top2 = record.top();
            record.push(top1);
            int newScore = top1 + top2;
            sum += newScore;
            record.push(newScore);
        }else{
            int num = stoi(op);
            sum += num;
            record.push(num);
        }
    }
    return sum;
    }
};