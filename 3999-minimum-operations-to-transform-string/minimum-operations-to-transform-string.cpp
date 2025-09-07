class Solution {
public:
    int minOperations(string s) {
        char small = 'z';
        int counta =0;
        for(char ch: s) {
            if(small > ch && ch != 'a') small = ch;
            if(ch == 'a') counta ++;
        }
        if(counta == s.size()) return 0;
        return 'z'-small+1;
    }
};