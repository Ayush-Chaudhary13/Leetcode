class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        set<int> set1(nums1.begin(), nums1.end());
        set<int> set2(nums2.begin(), nums2.end());

        int count1 = 0;
        for (int num : nums1) {
            if (set2.count(num)) {
                count1++;
            }
        }

        int count2 = 0;
        for (int num : nums2) {
            if (set1.count(num)) {
                count2++;
            }
        }

        return {count1, count2};
    }
};