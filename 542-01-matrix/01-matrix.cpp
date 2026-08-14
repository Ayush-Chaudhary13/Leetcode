class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {\

    int n = mat.size();
    int m = mat[0].size();
    queue<pair<int,int>> q;
    int arr[5] = {0,-1,0,1,0};

    for(int i =0; i<n; i++)
    {
        for(int j =0; j<m; j++)
        {
            if(mat[i][j] == 0)
            {
                q.push({i,j});
            }
            else mat[i][j] = INT_MAX;
        }
    }

    while(!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int i =0; i<4; i++)
        {
            int nr = r + arr[i];
            int nc = c + arr[i+1];

            if(nr>=0 && nc>=0 && nr<n && nc<m)
            {
                if(mat[nr][nc] > mat[r][c]+1)
                {
                    mat[nr][nc] = mat[r][c]+1;
                    q.push({nr,nc});
                }
            }
        }

    }
 return mat;
        
    }
};