class Solution {
public:
    string reverseWords(string s) {
        string ans ="";
        int i =0;

        while(i< s.length())
        {
            string word = "";
            while(s[i] != ' ' && i != s.length())
            {
                word += s[i];
                i++;
            }
            reverse(word.begin(), word.end());
            ans += word;
            if(i != s.length()) ans += ' ';
            i++;
        }
        return ans;
    }
};