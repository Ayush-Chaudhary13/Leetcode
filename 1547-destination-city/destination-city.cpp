class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> st;
        for(auto& it: paths)
        {
            st.insert(it[0]);
        }
        for(auto &path : paths)
        {
            string dest = path[1];
            if(st.find(dest) == st.end())return dest;
        }
        return "";
    }
};