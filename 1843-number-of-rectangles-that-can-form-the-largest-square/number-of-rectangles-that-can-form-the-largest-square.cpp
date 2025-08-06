class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int maxi = 0, count = 1;
        for(int i = 0, n = rectangles.size(); i < n; ++i){
            int len = min(rectangles[i][0] , rectangles[i][1]);
            if(len > maxi){
                maxi = len;
                count = 1;
            }
            else if(len == maxi) ++count;
        }
        return count;
    }
};