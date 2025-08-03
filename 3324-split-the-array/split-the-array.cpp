class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {

        if(nums.size()%2!=0) return false;
        unordered_map<int,int> mp;

        for(auto it: nums)
        {
            mp[it]++;
            if(mp[it]>2)return false;
        }
        return true;
    }
};