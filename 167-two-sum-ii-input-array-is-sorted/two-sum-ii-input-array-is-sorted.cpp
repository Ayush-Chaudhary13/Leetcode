class Solution {
public:
     vector<int> twoSum(vector<int>& a, int target) {
        int l = 0, r = a.size()-1;
        while (l< r) {
            if (a[l] + a[r] < target) {
                l++;
            }
            else if (a[l] + a[r] > target) {
                r--;
            }
            else {
                return vector<int> {l+1, r+1};
            }
        }
        return vector<int> {-1,-1};
    }
};