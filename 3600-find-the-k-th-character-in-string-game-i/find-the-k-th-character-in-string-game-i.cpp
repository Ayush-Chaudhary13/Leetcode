class Solution {
public:
    char kthCharacter(int k) {
        string s = "ab";
        while (s.size() < k) {
            int sz = s.size();
            for(int i =0; i<sz; i++) {
                if (s[i] == 'z')
                    s += 'a';
                else{
                    char ch = s[i] +1;
                    s += ch;
                }   
            }
        }
        return s[k - 1];
    }
};