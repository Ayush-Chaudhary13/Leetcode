class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = (int)languages.size();
        vector<bitset<512>> dp(m + 1);
        for (int i = 0; i < m; i++){
            for (int lang : languages[i])
                dp[i + 1].set(lang - 1);
        }   
        unordered_set<int> visited;
        for (auto & f : friendships){
            int u = f[0], v = f[1];
            bitset<512> inter = dp[u] & dp[v];
            if (inter.none()){
                visited.insert(u);
                visited.insert(v);
            }
        }
        if (visited.empty())
            return 0;
        vector<int> cnt(n + 1, 0);
        for (int u : visited){
            for (int lang = 1; lang <= n; lang++){
                if (dp[u].test(lang - 1))
                    cnt[lang]++;
            }
        }
        int best = *max_element(cnt.begin(), cnt.end());
        return (int)visited.size() - best;
    }
};