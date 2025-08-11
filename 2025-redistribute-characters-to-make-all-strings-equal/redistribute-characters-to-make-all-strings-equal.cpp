class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char,int>res;
        for(auto &word:words){
            for(char c:word)
            res[c]++;
        }
        for(auto i:res){
            if(i.second%words.size()!=0){
                return false;
            }
        }
        return true;
    }

};