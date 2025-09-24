class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it: roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<bool> vis(n + 1, false);
        vis[1] = 1;
        queue<int> q;
        q.push(1);
        int ans = INT_MAX;

        while(!q.empty()){
            int node  = q.front(); q.pop();
            for(auto [v,d]: adj[node]){
                   ans = min(ans,d);
                   if(!vis[v]){
                      vis[v] = true;
                      q.push(v);
                   }
           }
        }
        return ans;   
    }
};