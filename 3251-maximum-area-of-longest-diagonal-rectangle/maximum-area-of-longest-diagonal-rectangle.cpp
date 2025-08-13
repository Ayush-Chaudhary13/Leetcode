class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& d) {

        int maxd = INT_MIN, maxa = INT_MIN, count =0;

        for(int i=0; i<d.size(); i++) {
            int l = d[i][0];
            int b = d[i][1];
            int diagonal = pow(l,2) + pow(b,2);
            int area = l*b;
            if(diagonal > maxd) maxa = area;
            else if(diagonal == maxd) maxa = max(area,maxa);
             maxd = max(maxd,diagonal);
        }
        return maxa;
        
    }
};