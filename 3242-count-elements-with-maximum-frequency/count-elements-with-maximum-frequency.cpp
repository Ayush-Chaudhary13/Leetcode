class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        
        int freq=0;
        int mp[101]= {0};
        for(auto it : nums){
            mp[it]++;
            freq= max(freq, mp[it]);
        }

        int ans=0;

        for(auto it : mp){
             if(it == freq) ans += it;
        }
        return ans;
    }
};