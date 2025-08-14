class Solution {
public:
    char kthCharacter(int k) {
        string word = "a" ;
        cout<<word<<endl;;

        while(word.size() <k) {
            string p = word;
            cout<<p<<endl;
            for(auto i: p) {
                char next = 'a' + ((i-'a'+1)%26);
                cout<<next<<endl;
                word += next;
            }
        }
        return word[k-1];
    }
};