class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rect) {

        int count =0;
        int maxi = 0;

        for(auto r : rect )
        {
            int side = min(r[0], r[1]);

            if(side > maxi)
            {
               maxi = side;
               count =1;
            }

            else if(side == maxi)
            count++;
        }
        return count;
    }
};