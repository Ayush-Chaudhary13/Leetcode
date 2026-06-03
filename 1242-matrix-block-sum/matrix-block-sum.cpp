//optimal tc and sc o(m*n)
class Solution {
    //this fn is o(1)
    int sumRegion(vector<vector<int>>& prefix,int row1, int row2, int col1, int col2){
        int total = prefix[row2][col2];
        int left = (col1>0) ? prefix[row2][col1-1] : 0;
        int top = (row1>0) ? prefix[row1-1][col2] : 0;
        int topLeft = (row1 > 0 && col1>0) ? prefix[row1-1][col1-1] : 0;
        return total - left - top + topLeft;
    }
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int rows = mat.size();
        int cols = mat[0].size();
        vector<vector<int>> prefix(rows,vector<int>(cols));
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                int top = (i>0) ? prefix[i-1][j] : 0;
                int left = (j>0) ? prefix[i][j-1] : 0;
                int topLeft = (i>0 && j>0) ? prefix[i-1][j-1] : 0;
                prefix[i][j] = mat[i][j] + top + left - topLeft;
            }
        }
        vector<vector<int>> ans(rows,vector<int>(cols));
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                int row1 = max(0,i-k);
                int col1 = max(0,j-k);
                int row2 = min(rows-1,i+k);
                int col2 = min(cols-1,j+k);
                ans[i][j] = sumRegion(prefix,row1,row2,col1,col2);
            }
        }

        return ans;
    }
};