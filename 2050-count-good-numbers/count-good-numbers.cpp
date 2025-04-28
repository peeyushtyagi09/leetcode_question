class Solution {
public:
    const int MOD = 1e9 + 7;
    long long power(long long base, long long exp){
        long long result = 1;
        base %= MOD;
        while(exp > 0){
            if(exp % 2 == 1){
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            exp /= 2;
        }
        return result;
    }
    int countGoodNumbers(long long n) {
        long long evenposition = (n + 1)/2;
        long long oddposition = n / 2;
        return (power(5, evenposition) * power(4, oddposition)) % MOD;
    }
};