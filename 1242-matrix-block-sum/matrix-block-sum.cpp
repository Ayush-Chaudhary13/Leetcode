class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> pref = mat;
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 1; j < n; j++) {
                pref[i][j] += pref[i][j - 1];
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                pref[i][j] += pref[i - 1][j];
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int fi = min(m - 1, i + k);
                int fj = min(n - 1, j + k);
                ans[i][j] = pref[fi][fj];
                if (i - k - 1 >= 0) {
                    ans[i][j] -= pref[i - k - 1][fj];
                }
                if (j - k - 1 >= 0) {
                    ans[i][j] -= pref[fi][j - k - 1];
                }
                if (i - k - 1 >= 0 and j - k - 1 >= 0) {
                    ans[i][j] += pref[i - k - 1][j - k - 1];
                }
            }
        }
        return ans;
    }
};