class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<long, int> m;
        const int sz = nums1.size();
        for (int i = 0; i < sz; ++i) {
            for (int j = 0; j < sz; ++j) {
                m[nums1[i] + nums2[j]]++;
            }
        }
        int result = 0;
        for (int i = 0; i < sz; ++i) {
            for (int j = 0; j < sz; ++j) {
                result += m[-(nums3[i] + nums4[j])];
            }
        }
        return result;
    }
};