class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int sum =0;

        unordered_map<int,int>mp;
        for(auto it: nums)mp[it]++;

        for(auto it: mp) {
            if(it.second ==1)
              sum += it.first;
        }
        return sum;            
    }
};