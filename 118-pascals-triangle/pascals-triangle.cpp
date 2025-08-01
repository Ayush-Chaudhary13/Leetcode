class Solution {
public:

    vector<int> genrow(int row)
    {
        long long sol =1;
        vector<int> r;
        r.push_back(1);

        for(int col=1;col<row;col++)
        {
            sol=sol*(row-col);
            sol= sol/col;
            r.push_back(sol);
        }

        return r;

    }
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> ans;

        for(int i=1; i<= numRows;i++)
        {
            ans.push_back(genrow(i));
        }

        return ans;
        
    }
};