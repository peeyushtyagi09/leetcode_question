class Solution {
public:
    string removeDuplicates(string s) {
        // That is the brute approach of this question using string trversal
        // bool found = true;
        // while(found){
        //     found = false;
        //     string temp = "";
        //     for (int i = 0; i < s.length(); i++){
        //         if (i < s.length() - 1 && s[i] == s[i + 1]){
        //             i++;
        //             found = true;
        //         }else{
        //             temp += s[i];
        //         } 
        //     }
            
        //         s = temp;
        // }
        // return s;

// Complexity Analysis
// Time Complexity: O(n²) (since each pass scans O(n) and may require multiple passes).
// Space Complexity: O(n) (for storing the temporary string).

    stack<char> st;
    for (char ch : s){
        if(!st.empty() && st.top() == ch){
            st.pop();
        }else{
            st.push(ch);
        }
    }
    string result = "";
    while(!st.empty()){
        result = st.top() + result;
        st.pop();
    }
    return result;

    }
};