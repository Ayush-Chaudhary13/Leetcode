class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        
        vector<long long> powers;
        while (n > 0) {
            int rightmost_bit = n & (-n);  
            powers.push_back(rightmost_bit);
            n = n - rightmost_bit;       
        }
        
        
        vector<int> result;
        long long MOD = 1e9+7;
        
        for (auto query : queries) {
            int left = query[0];
            int right = query[1];
            
            long long product = 1;
            for (int i = left; i <= right; i++) {
                product = (product * powers[i]) % MOD;
            }
            
            result.push_back(product);
        }
        
        return result;
    }
};
