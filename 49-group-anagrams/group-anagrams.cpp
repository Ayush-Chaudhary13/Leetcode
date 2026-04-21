class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;

        for(auto x: strs)
        {
            auto cpy = x;
            sort(cpy.begin(), cpy.end());
            mp[cpy].push_back(x);   
        }

        for(auto it: mp)
        {
           ans.push_back(it.second);
        }
        return ans;
    }
};