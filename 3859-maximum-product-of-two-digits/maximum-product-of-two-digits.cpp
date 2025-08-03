class Solution {
public:
    int maxProduct(int n) {
        vector<int> digits;

        while(n>0)
        {
            int digit = n%10;
            digits.push_back(digit);
            n = n/10;
        }

        sort(digits.begin(), digits.end());

        int sz = digits.size()-1;

        int ans = digits[sz]*digits[sz-1];

        return ans;
        
    }
};