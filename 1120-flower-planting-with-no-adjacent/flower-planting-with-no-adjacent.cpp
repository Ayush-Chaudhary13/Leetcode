class Solution {
public:
    void bfs(int src, vector<vector<int>>& adj, vector<int>& color){

        queue<int>q;
        q.push(src);
        color[src-1] = 1;
        while(!q.empty()){
           int node = q.front();
           q.pop();
           int col = color[node-1];
           for(auto it: adj[node]){
               if(color[it-1] != 1 && color[it-1] != col) continue;

               else{
                  if(col < 4) color[it-1] = col+1;
                  else color[it-1] = 1;
                  q.push({it});
               }
           }
        }
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n+1);
        for(auto it: paths){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> color(n,1);

        for(int i =1; i<n; i++){
            if(color[i-1] == 1)
            bfs(i,adj,color);
        }
        return color;        
    }
};