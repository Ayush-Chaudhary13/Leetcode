class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> indegree(n,0);
        for(int i =0; i<edges.size(); i++)  indegree[edges[i][1]] = true;  
        vector<int> ans;
        for(int i=0; i<n; i++) if(!indegree[i]) ans.push_back(i);
        
        return ans;
    }
};