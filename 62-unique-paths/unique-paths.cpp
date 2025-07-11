class Solution {
public:
     int solve(int i,int j, vector<vector<int>> &dp)
     {
         if(i==1 && j==1)return 1;
        if(i<1 || j<1)return 0;

        if(dp[i][j] !=-1) return dp[i][j];

        int up= solve(i-1,j,dp);
        int left= solve(i,j-1,dp);

        return dp[i][j] = left + up; 
        
     }
     int uniquePaths(int m, int n) 
    {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return solve(m,n,dp);
    }
};