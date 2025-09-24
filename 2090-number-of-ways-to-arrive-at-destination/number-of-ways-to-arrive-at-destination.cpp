
#define P pair<long long,int>
class Solution {
public:
   void dikjstra(int s,vector<long long>&dist,vector<vector<P>> &adj ,int n,vector<int>&count){
    priority_queue<P,vector<P>,greater<P>>pq;
    const int mod = 1e9+7;
    dist[s]= 0;
    pq.push({0,0});
    count[0]=1;
    while(!pq.empty()){
        auto [d,u] = pq.top();
        pq.pop();
        if( d > dist[u]) continue;

        for(auto [v,w]:adj[u]) {
            if(dist[u] + w < dist[v]){
                count[v] = count[u];
                 dist[v] = dist[u] + w;
                pq.push({dist[v],v});
            }
             else if((dist[u] + w) == dist[v]){
                count[v] += count[u];
                count[v] %= mod;
            }

        }
    }
}
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<P>> adj(n);

        for(auto it: roads) {
                adj[it[0]].push_back({it[1],it[2]});
                adj[it[1]].push_back({it[0],it[2]});
        }

        vector<long long>dist(n, 1e18);
        vector<int>count(n,0);
        dikjstra(0,dist,adj,n,count);
        return count[n-1];
    }
};