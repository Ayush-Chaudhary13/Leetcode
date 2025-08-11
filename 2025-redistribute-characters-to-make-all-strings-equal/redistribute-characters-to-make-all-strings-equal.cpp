class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        unordered_map<char,int>mp;

        for(auto it: words)
        {
            for(int i=0; i<it.size(); i++)
            {
                mp[it[i]]++;
            }
        }

        for(auto it: mp)
        {
            if(it.second % n !=0) return false;
        }
        return true;
    }
};