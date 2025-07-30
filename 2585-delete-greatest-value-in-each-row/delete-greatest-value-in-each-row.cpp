class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        int elements = m*n;
        int ans =0;

        while(elements>0)
        {

            int maxi = INT_MIN;
            
            for(int i =0; i<m; i++)
            {
                int x=0, y=0;
                int local = INT_MIN;
                for(int j =0; j<n; j++)
                {
                    if(grid[i][j] == -1)continue;

                    if(grid[i][j] > local)
                    {
                        local = grid[i][j];
                        x= i;
                        y= j;
                    }

                    maxi = max(maxi,grid[i][j]);
                }
                grid[x][y] = -1;
                elements--;
            }
            ans += maxi;
        }
       return ans; 
    }
};