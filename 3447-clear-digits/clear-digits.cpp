class Solution {
public:
    string clearDigits(string s) {
        while(true){
        int n = s.length();
        bool found = false;
        for (int i = 0; i < n; i++){
            if(isdigit(s[i])){
                for (int j = i - 1; j >=  0; i--){
                    if(isalpha(s[j])){
                        s.erase(j, 1);
                        s.erase(i - 1, 1);
                        found = true;
                        break;
                    }
                }
                break;
            }
        }
        if (!found) break;
        }
        return s;
    }
};