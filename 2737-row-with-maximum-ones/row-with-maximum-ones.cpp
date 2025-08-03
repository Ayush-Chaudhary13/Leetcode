class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {

        int maxi=0, idx=0;

        for(int i = 0; i<mat.size(); i++)
        {
            int count =0;
            for(int val : mat[i])
            {
                if(val == 1) count++;
            }
            if(count> maxi)
            {
                maxi = count;
                idx = i;
            }
        }
        
        return {idx,maxi};
    }
};