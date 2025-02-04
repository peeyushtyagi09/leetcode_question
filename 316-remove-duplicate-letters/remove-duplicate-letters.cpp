class Solution {
public:
    string removeDuplicateLetters(string s) {

        //  without lexicographical order 
        // unordered_set<char> seen;
        // string result;
        // for (char ch : s){
        //     if (seen.find(ch) == seen.end()){
        //     result.push_back(ch);
        //     seen.insert(ch); 
        //     }
        // } 
        // return result;

        // with lexicographical order 
          unordered_map<char, int> freq;
        unordered_set<char> seen;
        stack<char> st;

        for (char ch : s) {
            freq[ch]++;
        }

        for (char ch : s) {
            freq[ch]--;
            if (seen.count(ch)) continue;

            while (!st.empty() && st.top() > ch && freq[st.top()] > 0) {
                seen.erase(st.top());
                st.pop();
            }

            st.push(ch);
            seen.insert(ch);
        }

        string result = "";
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }

        return result;
    }
};