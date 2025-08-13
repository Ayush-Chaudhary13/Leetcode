class Solution {
public:
    string findValidPair(string s) {
        string ans = "";
        unordered_map<char,int>mp;
        for(auto i : s) mp[i]++;

        for(int i =1; i<s.size(); i++) {
            if(s[i]!=s[i-1] && mp[s[i]]==s[i]-'0' && mp[s[i-1]] == s[i-1]-'0') {
                ans += s[i-1];
                ans += s[i];
                return ans;
            }
        }
        return ans;
    }
};