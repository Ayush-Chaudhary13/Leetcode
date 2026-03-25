class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int low =0, high =0, n = s.length();
        vector<int> mp(128,0);
        int ans = 0;

        for(high; high<n; high++)
        {
            mp[s[high]]++;
            while(mp[s[high]] > 1)
            {
                mp[s[low]]--;
                low++;
            }
            ans = max(ans, high-low+1);
        }
        if(s.length() == 0) return 0;
        return ans;
        
    }
};