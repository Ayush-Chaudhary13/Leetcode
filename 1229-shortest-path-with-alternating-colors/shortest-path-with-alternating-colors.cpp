// 1= red
// 0 = blue
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red, vector<vector<int>>& blue) {

        vector<vector<pair<int,int>>> adj(n);
        for(auto it: red ){
            adj[it[0]].push_back({it[1],1});
        }
        for(auto it: blue){
            adj[it[0]].push_back({it[1],0});
        }
        
        vector<vector<bool>> vis(n, vector<bool>(2, false));
        //vis[node][color]
        vis[0][0] = vis[0][1] = true;

        queue<vector<int>> q;
        q.push({0,-1,0});
        //{node,color,dist}

        vector<int> dist(n,INT_MAX);
        dist[0] = 0;

        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            
            int node = curr[0];
            int color = curr[1];
            int d = curr[2];
            

            for(auto it: adj[node]){
                auto [neibor, ncolor] = it;

                if(ncolor != color && !vis[neibor][ncolor] ){
                    vis[neibor][ncolor] = 1;
                    dist[neibor] = min(dist[neibor], d+1);
                    q.push({neibor,ncolor, d+1});
                }
            }
        }

        for(auto &i: dist){
            if(i == INT_MAX){
                i = -1;
            }
        }
        return dist;
        
    }
};