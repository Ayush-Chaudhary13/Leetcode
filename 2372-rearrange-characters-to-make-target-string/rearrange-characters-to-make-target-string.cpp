class Solution {
public:
    int rearrangeCharacters(string s, string target) {

        unordered_map<char,int> t;
        unordered_map<char,int> m;

        for(auto i : target) t[i]++;
        for(auto i: s) m[i]++;
        int copy =0,ans=INT_MAX;
        for(int i=0; i<target.size(); i++)
        {
            char ch = target[i];
            int x = m[ch];
            int y = t[ch];
            copy = floor(x/y);
            ans = min(ans,copy);
        }
        return ans;
    }
};