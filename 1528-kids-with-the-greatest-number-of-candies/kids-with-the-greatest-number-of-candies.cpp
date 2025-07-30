class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extra) {
        int n = candies.size();
        vector<bool> ans (n,0);
        int largest = candies[0];

        for(auto it: candies)
        {
            largest = max(largest, it);
         }

        for(int i =0; i< candies.size(); i++)
        {
            if(candies[i] + extra >= largest) ans[i] = 1;
    
        }
    return ans;
        
    }
};