class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& t,int n, vector<vector<int>>& dp){
        if(dp[i][j] != INT_MIN) return dp[i][j];

        if(i == n-1){
            return t[i][j];
        }

        int down = t[i][j] + solve(i+1, j, t, n, dp);
        int dia = t[i][j] + solve(i+1, j+1, t, n, dp);

        return dp[i][j] = min(down,dia);
    }
    int minimumTotal(vector<vector<int>>& t) {

        int n = t.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,INT_MIN));
        return solve(0,0,t,n,dp);   
    }
};