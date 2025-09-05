class MagicDictionary {
public:
    vector<string> v;
    MagicDictionary() {}
    
    void buildDict(vector<string> d) { v = d;}

    bool search(string s) {

        for(int i =0; i<v.size(); i++) {
            string str = v[i];
            if(str.length() != s.length() || str == s) continue;
            int count =0;
            for(int j =0; j<s.size(); j++) {
                if(str[j] != s[j]) {
                   count ++;
                   if(count> 1) break;
                }
            }
            if(count == 1) return true;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */