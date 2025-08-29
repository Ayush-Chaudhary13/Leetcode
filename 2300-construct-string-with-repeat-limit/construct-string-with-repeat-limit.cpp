class Solution {
public:
    string repeatLimitedString(string s, int lim) {
        vector<int> map(26,0);

        for(auto it: s){
            map[it- 'a']++;
        }

        string ans="";
        int i =25;

        while(i>=0)
        {
             if(map[i] == 0) {
                i--;
                continue;
             }

             char ch = 'a' + i;
             int freq = min(lim,map[i]);
             ans += string(freq,ch);
             map[i] -= freq;

             if(map[i] >0) {
                int j = i-1;
                while(j>=0 && map[j] == 0){
                    j--;
                    continue;
                }
                if(j<0)break;
                ans.push_back('a'+j);
                map[j]--;
             }
        }
        return  ans;
    }
};