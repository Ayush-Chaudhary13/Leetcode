class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        int high =0, low=0, maxi = INT_MIN;
        unordered_map<int,int> mp;

        for(high; high<fruits.size(); high++)
        {
            mp[fruits[high]]++;

            while(mp.size() > 2)
            {
                mp[fruits[low]]--;
                if(mp[fruits[low]] == 0) mp.erase(fruits[low]);
                low++;
            }
             int len = high - low + 1;
        maxi = max(maxi,len);
        }
       

        return maxi;
        
    }
};