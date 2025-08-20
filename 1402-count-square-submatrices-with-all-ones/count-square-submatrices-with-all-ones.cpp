class Solution{
public:
    int dp[305][305]; 
    int countSquares(vector<vector<int>>& matrix) {
        int ans = 0;
        int r = matrix.size(), c = matrix[0].size();
        for(int i = 1; i <= r; ++i){
            for(int j = 1; j <= c; ++j){
                if(matrix[i-1][j-1] == 1){
                    dp[i][j] = min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]}) + 1;
                    ans += dp[i][j];
                }
            }
        }
        return ans;
    }
};