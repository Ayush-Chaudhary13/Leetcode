class Solution {
public:
    long long flowerGame(int n, int m) {
        long long ans =0;

        long long oddx = (n+1)/2, evenx = n/2, oddy = (m+1)/2, eveny = m/2;
        ans = (oddx*eveny) + (evenx*oddy);
        return ans;
        
    }
};