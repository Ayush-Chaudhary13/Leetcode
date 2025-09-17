class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<vector<int>>& ans,    vector<int>& temp, int n) {
        if(node == n-1) {
            ans.push_back(temp);
            return;
        }
        for(auto it: graph[node]) {
            temp.push_back(it);
            dfs(it,graph, ans, temp,n);
            temp.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<vector<int>> ans;
        int n = graph.size();
        vector<int> temp;
        temp.push_back(0);

        dfs(0,graph,ans,temp,n);
        return ans;
    }
};