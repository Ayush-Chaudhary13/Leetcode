class Solution {
public:
    int distinctAverages(vector<int>& nums) {

        if(nums.size() <=1) return 0;
        sort(nums.begin(), nums.end());
        int l=0, r= nums.size()-1;
        set<double> Avg;
        while(l<r)
        {
            
            double avg = (nums[l] + nums[r])/2.0;
            Avg.insert(avg);
            l++;
            r--;
        }

        return Avg.size();
    }
};