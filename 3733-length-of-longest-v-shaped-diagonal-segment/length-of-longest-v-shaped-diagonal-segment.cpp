class Solution {
public:
    int n,m;
    vector<vector<int>> g;
    vector<pair<int,int>> directions = {{1,1},{1,-1},{-1,-1},{-1,1},{1,1}};
    int dp[500][500][5][2][3];

    int solve(int i, int j, int dir, int turned, int expected ) {
        if(i<0 || j<0 || i>=n || j>=m)return 0;
        
        if(g[i][j] != expected) return 0;
        if(dp[i][j][dir][turned][expected] != -1) return dp[i][j][dir][turned][expected];

        int next;
        if(expected == 1) next =2;
        else if(expected == 2) next =0;
        else next = 2;

        int no =0;
        int ni = i+ directions[dir].first;
        int nj = j+ directions[dir].second;
        no = 1+ solve(ni,nj,dir,turned,next);

        int yes;
        if(!turned) {
            int ni = i + directions[dir+1].first;
            int nj = j + directions[dir+1].second;
            yes = 1 + solve(ni,nj,dir+1,1,next);

        }

        return dp[i][j][dir][turned][expected] = max(no,yes);

    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        g = grid;
        n = grid.size();
        m= grid[0].size();
        memset(dp,-1,sizeof(dp));
        int ans =0;

        for(int i =0; i<n; i++) {
            for(int j =0; j<m; j++) {
                if(g[i][j] == 1) {
                    for(int dir =0; dir<4; dir++) {
                       ans = max(ans, solve(i,j,dir,0,1));
                    }
                }
            }
        }

       return ans; 
    }
};