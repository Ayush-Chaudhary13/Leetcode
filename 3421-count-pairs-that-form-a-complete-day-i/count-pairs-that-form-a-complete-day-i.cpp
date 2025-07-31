class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {

        unordered_map<int, int> mp;
        int count =0;

        for(auto i: hours)
        {
            int remainder = i%24;
            if(remainder ==0)
                count += mp[0];
            else
               count += mp[24-remainder];

            mp[remainder]++;   
        }
        return count;
        
    }
};