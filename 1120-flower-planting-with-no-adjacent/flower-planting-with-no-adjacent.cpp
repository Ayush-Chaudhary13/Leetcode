class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n+1);
        for(auto& path : paths) {
            int u = path[0], v = path[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> color(n, 0);
        
        for(int i = 1; i <= n; i++) {
            bool used[5] = {false};
            for(int neighbor : adj[i]) {
                used[color[neighbor-1]] = true;
            }
            for(int c = 1; c <= 4; c++) {
                if(!used[c]) {
                    color[i-1] = c;
                    break;
                }
            }
        }
        return color;
    }
};