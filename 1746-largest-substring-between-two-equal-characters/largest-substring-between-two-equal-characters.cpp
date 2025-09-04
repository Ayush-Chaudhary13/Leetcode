class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {

        unordered_map<char, int> mpp;
        bool found = false;
        int ans = -1;

        for(int i =0; i<s.size(); i++) {
            if(mpp.find(s[i]) == mpp.end()) mpp[s[i]]= i;
            else 
            {
                int x =  i - mpp[s[i]] - 1;
                ans = max(ans,x);
            }
            
        }
       return ans;  
    }
};