class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red, vector<vector<int>>& blue) {
        vector<vector<pair<int,int>>> list(n);
        for(auto &r : red) {
            int u = r[0], v = r[1];
            list[u].push_back({v, 1});
        }
        for(auto &b : blue) {
            int u = b[0], v = b[1];
            list[u].push_back({v, 0}); 
        }
        vector<vector<int>> dist(n, vector<int>(2, INT_MAX));
        queue<tuple<int,int,int>> q;
        dist[0][0] = dist[0][1] = 0;
        q.push({0, 0, -1}); 
        while(!q.empty()) {
            auto [node, step, prev] = q.front();
            q.pop();
            for(auto &nbr : list[node]) {
                int nxt = nbr.first, color = nbr.second;
                if(color == prev) continue; 
                if(step+1 < dist[nxt][color]) {
                    dist[nxt][color] = step+1;
                    q.push({nxt, step+1, color});
                }
            }
        }
        vector<int> ans(n, -1);
        for(int i = 0; i < n; i++) {
            int d = min(dist[i][0], dist[i][1]);
            if(d != INT_MAX) ans[i] = d;
        }
        return ans;
    }
};