class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        // bottom left
        

        for(int i =0; i<n; i++) {
            int j =0,ic=i;
            vector<int> temp;
            while(ic<n && j<n) {
                temp.push_back(grid[ic++][j++]);
            }
            sort(temp.begin(),temp.end());
            ic =i;
            j =0;
            int k = temp.size()-1;
            while(k>=0){
                grid[ic++][j++] = temp[k--];
             }
        }

        // top right

        for(int j = 1; j<n; j++) {
            int i =0, jc= j;
            vector<int> temp;
            while(i<n && jc<n) {
                temp.push_back(grid[i++][jc++]);
            }
            sort(temp.begin(),temp.end());
            int k = 0;
            i=0, jc = j;
            while(k<temp.size()) {
                grid[i++][jc++] = temp[k++];
            }
        }
        return grid;
    }
};