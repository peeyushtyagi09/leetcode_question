class Solution {
public:
    int maxDifference(string s) {
        if (s.length() < 3) return -1;
        unordered_map<char, int> freq;
        for (char ch : s){
            freq[ch]++;
        }

        int max_even = INT_MAX;
        int max_odd = INT_MIN;

        for (auto str : freq){
            if(str.second < max_even && str.second % 2 == 0){
                max_even = str.second;
            }
            if(str.second > max_odd && str.second % 2 != 0){
                max_odd = str.second;
            }
        }
        return max_odd - max_even;

        // int max_diff = -1;
        // for (auto &[odd_ch, odd_count] : freq){
        //     if(odd_count % 2 == 0) continue;
        //     for (auto &[even_ch, even_count] : freq){
        //         if (even_count % 2 != 0) continue;
        //         max_diff = max(max_diff, odd_count - even_count);
        //     }
        // }
        // return max_diff;
    }
};