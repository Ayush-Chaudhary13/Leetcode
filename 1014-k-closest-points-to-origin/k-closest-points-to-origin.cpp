class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        vector<vector<int>> ans(k);
        priority_queue<vector<int>> maxheap;

        for(auto& p: points)
        {   int x= p[0],y=p[1];
            maxheap.push({x*x + y*y, x, y});
             if (maxheap.size() > k) { maxheap.pop(); }
        }
        
        for (int i = 0; i < k; ++i) {
            vector<int> top = maxheap.top();
            maxheap.pop();
            ans[i] = {top[1], top[2]};
        }
        
        return ans;
     }
};