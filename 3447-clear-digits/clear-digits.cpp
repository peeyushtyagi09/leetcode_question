class Solution {
public:
    string clearDigits(string s) {
        // but the is brute olution it has time complexity of O(n2)
        // while(true){
        // int n = s.length();
        // bool found = false;
        // for (int i = 0; i < n; i++){
        //     if(isdigit(s[i])){
        //         for (int j = i - 1; j >=  0; i--){
        //             if(isalpha(s[j])){
        //                 s.erase(j, 1);
        //                 s.erase(i - 1, 1);
        //                 found = true;
        //                 break;
        //             }
        //         }
        //         break;
        //     }
        // }
        // if (!found) break;
        // }
        // return s;

        // That one is the optimal solution in this we are using an stack;
        stack<char> st;
        for (char ch : s){
            if(isdigit(ch)){
                if(!st.empty()) st.pop();
            }else{
                st.push(ch);
            }
        }
        string str = "";
        while(!st.empty()){
            str += st.top();
            st.pop();
        }
         reverse(str.begin(), str.end());
        return str;
    }
};