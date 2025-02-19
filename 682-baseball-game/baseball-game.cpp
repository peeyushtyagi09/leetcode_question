class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int>record;
        for (string st : ops){
            if (st == "C"){
                record.pop_back();
            }else if (st == "D"){
                record.push_back(2 * record.back());
            }else if (st == "+"){
                int n = record.size();
                record.push_back(record[n - 1] + record[n - 2]);
            }else{
                record.push_back(stoi(st));
            }
        }
        int sum = 0;
        for(int num : record){
            sum += num;
        }
        return sum;
    }
};