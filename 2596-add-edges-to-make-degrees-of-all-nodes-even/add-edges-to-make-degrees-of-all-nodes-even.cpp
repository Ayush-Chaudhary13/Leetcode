class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> adj(n + 1);
        for (auto& e : edges) {
            adj[e[0]].insert(e[1]);
            adj[e[1]].insert(e[0]);
        }
        vector<int> odd;
        for (int i = 1; i <= n; i++) {
            if (adj[i].size() % 2 != 0)odd.push_back(i);   
        }
        if (odd.size() == 0) return true;
        if (odd.size() != 2 && odd.size() != 4) return false;
        if (odd.size() == 2) {
            int a = odd[0], b = odd[1];
            if (adj[a].find(b) == adj[a].end()) return true;
            for (int i = 1; i <= n; i++) {
                if (i != a && i != b && 
                    adj[i].find(a) == adj[i].end() && 
                    adj[i].find(b) == adj[i].end()) {
                    return true;
                }
            }
            return false;
        }
        int a = odd[0], b = odd[1], c = odd[2], d = odd[3];
    if (adj[a].find(b) == adj[a].end() && adj[c].find(d) == adj[c].end())return true;
    if (adj[a].find(c) == adj[a].end() && adj[b].find(d) == adj[b].end())return true;
    if (adj[a].find(d) == adj[a].end() && adj[b].find(c) == adj[b].end())return true;
    return false;
    }
};