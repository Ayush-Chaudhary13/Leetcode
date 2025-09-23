class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        
        vector<int> degree(n,0);

        for(auto it: roads){
            degree[it[0]]++;
            degree[it[1]]++;
        }
        vector<int> cities(n);
        for(int i =0; i<n; i++){
            cities[i] = i;
        }

        sort(cities.begin(), cities.end(), [&](int a, int b){
            return degree[a] > degree[b];
        });

        long long ans =0;
        for(int i =0; i<n; i++){
            ans += (long long)(n-i)* degree[cities[i]];
        }

        return ans;
    }
};