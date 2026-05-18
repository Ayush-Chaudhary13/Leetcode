class Solution {
public:
    int maxArea(vector<int>& height) {

        int j = height.size()-1;
        int i =0;
        int maxi = INT_MIN;

        while(i<j)
        {
            int area = min(height[i], height[j]) * (j-i);
            maxi = max(area,maxi);
            if(height[i]<=height[j])i++;
            else j--;
        }
        return maxi;
    }
};