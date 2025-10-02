class Solution {
public:
    vector<vector<int>> graph;
    vector<int> sz, val;

    void dfs1(int node, int parent){

        for(int child : graph[node]){
            if(child != parent){
                dfs1(child,node);
                sz[node] += sz[child];
                val[node] += val[child] + sz[child];
            }
        }
        sz[node]++;
    }

    void dfs2(int node, int parent, int n){
        if(parent != -1) val[node] = val[parent] - sz[node] + (n-sz[node]);

        for(int child : graph[node]){
            if(child == parent) continue;
            dfs2(child,node,n);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        graph.resize(n), sz.resize(n), val.resize(n);

        for(auto it: edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }

        dfs1(0,0);
        dfs2(0,-1,n);
        return val;
    }
};