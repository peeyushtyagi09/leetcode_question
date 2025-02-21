class Solution {
public:
    string reversePrefix(string word, char ch) {
        // brute force approach of that code 
        // step1 : find the first occurance of that character 
        // step2 : Then reverse that from 0 to the index of that first occurance
        // step3 : then return that reverse string + remmaning string

        int index = -1;
        for(int i = 0; i < word.length(); i++){
            if (word[i] == ch){
                index = i;
                break;
            }
        }
        if (index == -1) return word;
        string prefix = word.substr(0, index + 1);
        reverse(prefix.begin(), prefix.end());

        return prefix + word.substr(index + 1);
    }
};