#include<bits/stdc++.h>
#define pii pair<long long,int>
class Solution {
public:
   void dikjstra(int s,vector<long long>&dist,vector<vector<pii>>&adj,int n,vector<int>&count){
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    int mod = 1e9+7;
    dist[s]=0ll;
    pq.push({dist[s],s});
    count[s]=1;
    while(!pq.empty()){
        int u=pq.top().second;
        long long D=pq.top().first;
        pq.pop();
        if(D>dist[u]) continue;
        for(auto p:adj[u]){
            int v=p.first;
            int w=p.second;
            if(dist[u]+w<dist[v]){
                count[v]=count[u];
                dist[v]=dist[u]+w;
                pq.push({dist[v],v});
            }
             else if((dist[u]+w)==dist[v]){
                count[v]+=count[u];
                count[v]%=mod;
            }

        }
    }
}
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pii>>adj(n);
        for(int i=0;i<roads.size();i++){
                adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
                adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        vector<long long>dist(n, 1e18);
        vector<int>count(n,0);
        dikjstra(0,dist,adj,n,count);
        return count[n-1];
    }
};