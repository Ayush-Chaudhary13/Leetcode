class Solution {
public:
void dfs(int node,  vector<vector<int>>& adj, vector<bool>& vis, int &n, int &e ) 
    {  
        vis[node] = 1;
        n++;
        e += adj[node].size();
        for(auto it: adj[node]) {
            if(!vis[it])
            dfs(it,adj,vis,n,e);
        }
        return;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);
        for(auto it: edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<bool> vis(n,0);
        int ans =0;

        for(int i =0; i<n; i++) {
            if(!vis[i]) {
                int n=0, e=0;
                dfs(i,adj,vis,n,e);
                if(n*(n-1) ==  e) ans++;
            }
        }
       return ans;
        
    }
};