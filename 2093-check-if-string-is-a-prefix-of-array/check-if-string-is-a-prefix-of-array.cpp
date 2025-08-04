class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string p = "";
        for (auto i : words) {
            p += i;
            if (s == p)
                return true;
            if (s.find(p) != 0)
                break;
        }
        return false;
    }
};