class Solution {
public:

    bool check(vector<int>& nums)
    {
        for(int i =0; i<nums.size(); i++)
        {
            if(nums[i] !=0) return false;
        }
        return true;

    }

    int small(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int i =0;
        while(nums[i] == 0)i++;

        return nums[i];
    }

    void subs(int smallest, vector<int>& nums)
    {
        for(int i =0; i<nums.size(); i++)
        {
            if(nums[i] !=0)
            {
                nums[i] -= smallest;
            }
        }
    }
    int minimumOperations(vector<int>& nums) {

        int count =0;
        bool chk = 0;

        while(!chk)
        {
            chk = check(nums);
            if(chk) break;
            int smallest = small(nums);
            subs(smallest, nums);
            count++;
        }

        return count;
    }
};