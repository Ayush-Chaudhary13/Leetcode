class Solution {
public:
    long long flowerGame(int n, int m) {
        long long ans =0;
        ans = ((static_cast<long long>(n+1)/2)*(m/2)) + ((n/2)*(static_cast<long long>(m+1)/2));
        return ans;
        
    }
};