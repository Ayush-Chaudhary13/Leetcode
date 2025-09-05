class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {

        string ans = "";
        int length = 0;

        for(int i =0; i<d.size(); i++) {
            string cmp = d[i];
            int x =0,y=0;
            if(ans.size() <= cmp.size()) {
                while(x < s.size() && y < cmp.size()) {
                    if(s[x] == cmp[y]) {
                        x++,y++;
                    }
                    else x++;
                }
                if(y == cmp.size()) {
                    if(cmp.size() > ans.size()) ans = cmp;
                    else ans = min(ans,cmp);
                }

            }
        }
        return ans;
    }
};