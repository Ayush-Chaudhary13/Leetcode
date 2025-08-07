class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {

        vector<int> ans;
        for (int i = 1; i < nums.size(); i += 2) {
            int freq = nums[i - 1];
            int val = nums[i];
            while (freq > 0) {
                ans.push_back(val);
                freq--;
            }
        }
        return ans;
    }
};