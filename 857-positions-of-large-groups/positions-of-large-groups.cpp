class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {

        int start=0, end =0;
        vector<vector<int>> ans;

        for(int i=1; i<s.length(); i++)
        {
            if(s[i]==s[i-1]) continue;

            else
            {
                end = i-1;
                int length = end - start +1;

                if(length>=3) ans.push_back({start,end});
                start = i;
            }
        }
    if (s.length() - start >= 3)
    ans.push_back({start, (int)s.length() - 1});

        return ans;
        
    }
};