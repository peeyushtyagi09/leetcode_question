class Solution {
public:
int sub(string &string1, string &string2){
    if (string1.size() < string2.size()) swap(string1, string2);
    int m = string1.size(), n = string2.size();

    vector<int>prev(n + 1, 0), curr(n + 1, 0);
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            if(string1[i - 1] == string2[j - 1]){
                curr[j] = 1 + prev[j - 1];
            }else{
                curr[j] = max(prev[j], curr[j - 1]);
            }
        }
        swap(prev, curr);
    }
    return prev[n];
}
    int longestPalindromeSubseq(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        int ans = sub(s, rev_s);
        return ans;
    }
};