class Solution {
public:
    int minh = INT_MAX;
    vector<vector<int>> graph;
    vector<pair<int,int>> dp;
 
    int dfs(int node,int parent)
    {
        int m1=0,m2=0,tmp;
        
        for(int &neibor:graph[node])
        {
            if(neibor!=parent)
            {
                tmp = 1 + dfs(neibor,node);
                if(tmp>m1)
                {
                    m2 = m1;
                    m1 =tmp;
                }
                else if(tmp>m2)
                {
                    m2 = tmp;
                }
            }
        }
        dp[node] = {m1,m2};
        return max(m1,m2);
    }
    void reroot(int node,int parent)
    {
       minh = min(minh,dp[node].first);
       int extra; 
        
       for(int &neibor:graph[node])
       {
           if(neibor!=parent)
           { 
               if(dp[neibor].first+1==dp[node].first)
                   extra = dp[node].second;
               else
                   extra = dp[node].first;

               if(1+extra>dp[neibor].first)
               {
                   dp[neibor].second = dp[neibor].first;
                   dp[neibor].first = 1 + extra;
               }
               else if(1+extra>dp[neibor].second)
               {
                   dp[neibor].second = 1 + extra;
               }
               
               reroot(neibor,node);
           }
       }
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        graph.resize(n);
        dp.resize(n);
        for(vector<int>&edge:edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        dfs(0,-1);

        reroot(0,-1);

        vector<int> ans;
        for(int i = 0;i<n;i++)
            if(dp[i].first==minh)
                ans.push_back(i);
        return ans;
    }
};