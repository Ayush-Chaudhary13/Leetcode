class Solution {
public:
    int help(vector<int>& mp)
    {
        int ans =0;
        for(int i =0; i<mp.size(); i++) ans = max(ans, mp[i]);

        return ans;
    }
    int characterReplacement(string s, int k) {

        vector<int> mp(26,0);
        int l=0, r=0,maxi= INT_MIN;

        for(r; r<s.length(); r++)
        {
            mp[s[r] - 'A']++;
            int len = r-l+1;
            int maxcnt = help(mp);
            int diff = len-maxcnt;

            while(diff > k)
            {
                mp[s[l] - 'A']--;
                l++;
                len = r-l+1;
                maxcnt = help(mp);
                diff = len - maxcnt;
            }

            int sz = r-l+1;
            maxi = max(maxi,sz);
        }

        return maxi;
        
    }
};