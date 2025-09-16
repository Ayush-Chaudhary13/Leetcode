class DisjointSet {
    vector<int> parent, size;
public:
    DisjointSet(int n) {
        parent.resize(n + 1, 0); 
        size.resize(n + 1, 0); 
        for (int i = 0; i < n; i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }
    int findParent(int node) {
        
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionsize(int u, int v) {
        
        int p_u = findParent(u);
        int p_v = findParent(v);
        if (p_u == p_v) return; 

        
        if (size[p_u] < size[p_v]) {
            parent[p_u] = p_v;
            size[p_v] += size[p_u];
        } else {
            parent[p_v] = p_u;
            size[p_u] += size[p_v];
        }
    }
};

class Solution {
public:
       
     vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) 
    {
        int n= accounts.size();
        DisjointSet ds(n);
        sort(accounts.begin(),accounts.end());

        unordered_map<string,int>mp;

        for(int i=0;i<n;i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
                string mail= accounts[i][j];
                if(mp.find(mail)==mp.end())
                {
                    mp[mail]=i;
                }
                else
                {
                    ds.unionsize(i,mp[mail]);
                }
            }
        }

        vector<string> mergeacc[n];
        for(auto it:mp)
        {
            int idx= it.second;
            string mail= it.first;
            int parent= ds.findParent(idx);
            mergeacc[parent].push_back(mail);
        }
        vector<vector<string>> ans;
        for(int i=0;i<n;i++)
        {
            if(mergeacc[i].empty())continue;
            sort(mergeacc[i].begin(),mergeacc[i].end());
            vector<string> tmp;
            tmp.push_back(accounts[i][0]);
            for(int j=0;j<mergeacc[i].size();j++)
            {
                tmp.push_back(mergeacc[i][j]);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};