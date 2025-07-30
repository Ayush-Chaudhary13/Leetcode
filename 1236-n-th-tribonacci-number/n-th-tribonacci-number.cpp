class Solution {
public:
    int solve(vector<int>& dp, int n) {
        if (dp[n] != -1)
            return dp[n];

        dp[n] = solve(dp, n - 1) + solve(dp, n - 2) + solve(dp, n - 3);
        return dp[n];
    }
    int tribonacci(int n) {
        if (n == 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;

        vector<int> dp(n + 1, -1);

        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;

        return solve(dp, n);
    }
};