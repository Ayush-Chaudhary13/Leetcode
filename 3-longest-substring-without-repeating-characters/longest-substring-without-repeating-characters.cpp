class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int l=0,r=0, maxi = INT_MIN;
        unordered_map<char,int> mp;

        for(r; r<s.size(); r++)
        {
            mp[s[r]]++;
            int len = r-l+1;
            while(mp.size() < len)
            {
                mp[s[l]]--;
                if(mp[s[l]] == 0) mp.erase(s[l]);
                l++;
                len = r-l+1;
            }
            maxi = max(maxi, r-l+1); 
        }
        if(s.size() == 0) return 0;
       return maxi; 
    }
};