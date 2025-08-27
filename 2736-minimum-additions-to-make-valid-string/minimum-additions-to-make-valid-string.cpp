class Solution {
public:
    int addMinimum(string word) {
        
        int ans =0;
        int i =0,j=0;
        string s = "abc";

        while(i<word.size()) {
            if(word[i] == s[j]) 
            {
                i++,j++;
            }
            else {
                ans++;
                j++;
            }
            if(j==3)j = 0;
        }
        if(word.back() == 'a') ans+=2;
        else if(word.back() == 'b') ans++;
        return ans;
    
    }
};