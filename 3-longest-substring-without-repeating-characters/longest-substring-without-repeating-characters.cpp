class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int low =0, high =0, n = s.length();
        unordered_map<char,int> mp;
        int ans = INT_MIN;

        for(high; high<n; high++)
        {
            mp[s[high]]++;
            int len= high-low+1;
            while(mp.size() < len)
            {
                mp[s[low]]--;
                if(mp[s[low]] == 0)mp.erase(s[low]);
                low++;
                len = high-low+1;
            }
            ans = max(ans, high-low+1);
        }
        if(s.length() == 0) return 0;
        return ans;
        
    }
};