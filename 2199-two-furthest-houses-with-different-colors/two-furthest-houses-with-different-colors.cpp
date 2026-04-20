class Solution {
public:
    int maxDistance(vector<int>& colors) {
        
        int ans=0, n = colors.size();

        for(int i =1; i<n; i++)
        {
          if(colors[i] != colors[0]) ans = max(ans,i);
          if(colors[i] != colors[n-1]) ans = max(ans, n-1-i);
        }
        return ans;
    }
};