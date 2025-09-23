typedef long long int ll;
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0); 
        for(auto & edge : roads){
            int u = edge[0], v = edge[1];
            degree[u]++; 
            degree[v]++;
        }

        sort(degree.begin(), degree.end());
        ll ans = 0, val = 1;
        for(auto deg : degree){
            // cout<<deg*val<<endl;
            ans += deg * val;
            val++;
        }

        return ans;
    }
};