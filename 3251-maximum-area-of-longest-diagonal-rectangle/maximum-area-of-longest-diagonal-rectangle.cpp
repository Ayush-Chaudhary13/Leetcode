class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& d) {

        int maxd = INT_MIN, maxa = INT_MIN, count =0;

        for(int i=0; i<d.size(); i++) {
            int dia = pow(d[i][0],2) + pow(d[i][1],2);
            int area = d[i][1] * d[i][0] ;
            if(dia > maxd) maxa = area;
            else if(dia == maxd) maxa = max(area,maxa);
             maxd = max(maxd,dia);
        }
        return maxa;
        
    }
};