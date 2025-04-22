class Solution {
public:
int equaltogoal(vector<int>& nums, int goal){
    if(goal < 0) return 0;
    int l=0;
    int r=0;
    int count = 0;
    int sum = 0;
    while(r<nums.size()){
        sum = sum + nums[r];
        while(sum > goal){
            sum = sum - nums[l];
            l++;
        }
        count = count + (r-l+1);
        r++;
    }
    return count;
}
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int goal2 = equaltogoal(nums,goal);
        int goal1 = equaltogoal(nums,goal-1);
        return goal2-goal1;
    }
};