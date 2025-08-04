class Solution {
public:
    int findLHS(vector<int>& nums) {

        unordered_map<int,int> mp;

        for(auto it: nums){ mp[it]++;} 
        int ans =0;

        for(auto& [key,val]: mp)
        {
            if(mp.count(key+1))
            { 
                ans = max(ans,val+ mp[key+1]);
            
            }

        }
        return ans;
    }
};