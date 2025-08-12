class Solution {
public:
    string capitalizeTitle(string title) {
        string s = "";
        vector<string> v;

        for(int i =0; i<title.size(); i++)
        {
            if(title[i] != ' ') s += title[i];
            else
            {
                v.push_back(s);
                s = "";
            }
        }
        v.push_back(s);

        string ans;
        for(int i =0; i<v.size(); i++)
        {
            string add = v[i];
            for(auto &a : add) a = tolower(a);
            if(add.size() <=2)
            {
                ans += add;
            }
            else
            {
                add[0] = toupper(add[0]);
                ans += add;
            }
            if( i != v.size()-1) ans +=" ";
        }
        return ans;
    }
};