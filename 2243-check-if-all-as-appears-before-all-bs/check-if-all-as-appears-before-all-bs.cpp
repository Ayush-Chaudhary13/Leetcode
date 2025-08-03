class Solution {
public:
    bool checkString(string s) {
        bool flag = 0;

        for (char c : s) {
            if (c == 'b')
                flag = 1;
            if (flag && c == 'a')
                return false;
        }
        return true;
    }
};