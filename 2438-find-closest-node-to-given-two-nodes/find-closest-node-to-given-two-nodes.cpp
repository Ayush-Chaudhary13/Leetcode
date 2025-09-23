class Solution {
public:
#define P pair<int,int>

vector<int> dj(int src, vector<int>& adj, int n){
     
     priority_queue<P> pq;
     vector<int> dist(n, 1e9);
     dist[src] = 0;
     pq.push({0,src});
     
     while(!pq.empty()){
         auto [dis, node] = pq.top();
         pq.pop();
         
         if(adj[node] != -1){
             if(dis + 1 < dist[adj[node]]){
                 dist[adj[node]] = dis + 1;
                 pq.push({dis + 1, adj[node]});
             }
         }
     }
     
     return dist;  
}

int closestMeetingNode(vector<int>& edges, int node1, int node2) {
    int n = edges.size();
    
    vector<int> d1 = dj(node1, edges, n);
    vector<int> d2 = dj(node2, edges, n);
    
    int mini = INT_MAX;
    int idx = -1;
    
    for(int i =0; i<n; i++){
        if(d1[i] == 1e9 || d2[i] == 1e9) continue;
        
        if(mini > max(d1[i], d2[i])){
            mini = max(d1[i], d2[i]);
            idx = i;
        }
        
    }
    return idx;       
  }
};