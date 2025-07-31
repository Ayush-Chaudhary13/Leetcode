class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n=points.size();
        double ans = 0;
        for(int i=0; i<n-2; i++) {
            for(int j=i+1; j<n-1; j++) {
                for(int k=i+2; k<n; k++) {
                    double area = 0.5*abs(
                        1.0*points[i][0]*(points[j][1]-points[k][1]) +
                        1.0*points[j][0]*(points[k][1]-points[i][1]) +
                        1.0*points[k][0]*(points[i][1]-points[j][1])
                    );
                    if(area > ans) ans = area;
                }
            }
        }
        return ans;
    }
};