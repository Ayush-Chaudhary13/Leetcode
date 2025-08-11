class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {

        vector<int> ans;
        int currw =0, linecnt=1;
        
        for(int i =0; i < s.size(); i++)
        {
            char ch = s[i];
            int width = widths[ch-'a'];
            if(currw + width > 100)
            {
                currw = width;
                linecnt++;
            }
            else
            {
                currw += width;
            }
        }
        ans.push_back(linecnt);
        ans.push_back(currw);

        return ans;
        
    }
};