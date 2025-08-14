class Solution {
public:
    char kthCharacter(int k) {
        string word = "a" ;
        while(word.size() <k) {
            string p = word;
            for(auto i: p) {
                char next = 'a' + ((i-'a'+1)%26);
                word += next;
            }
        }
        return word[k-1];
    }
};