class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.size();
        if(n ==1)return 0;
        if(n ==2 ) {
            if(s[0] != s[1]) return 1;
            else return 0;
        }
       
        int ans =0;
        for(int i =0; i<s.size()-2; i++) {
            if(s[i] != s[i+1] && s[i+1] != s[i+2] && s[i] != s[i+2]) ans++;
        }
        return ans;
    }
};