class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> ans(s.size(),0);

        for(int i=0; i<s.size(); i++) {
            if(s[i] == c) continue;
            int mini = INT_MAX;
            for(int j =0; j<s.size(); j++) {
                if(s[j] == c){
                    int d = abs(i-j);
                    mini = min(mini, d);   
                }
            }
            ans[i] = mini;
        }
        return ans;
    }
};