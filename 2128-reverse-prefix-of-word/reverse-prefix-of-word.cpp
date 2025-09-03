class Solution {
public:
    string reversePrefix(string word, char ch) {

        string rev = "";
        bool flag = false;
        for(auto it: word) {
            rev += it;
            if(it == ch) {
                flag = true;
                break;
            } 
        }
        if(flag) {
            reverse(rev.begin(),rev.end());
            for(int i =0; i<rev.size(); i++) {
                word[i] = rev[i];
            }
            return word;
        }
        return word;
        
    }
};