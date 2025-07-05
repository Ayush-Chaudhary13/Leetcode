class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        vector<vector<int>> ans;

        int n= nums.size();
        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++)
        {
            if(i>0 && nums[i] == nums[i-1])continue;

            for(int j= i+1; j<n; j++)
            {
                if(j>i+1 && nums[j] == nums[j-1])continue;

                int x= j+1;
                int y= n-1;

                while(x < y)
                {
                    long long sum = nums[i];
                      sum += nums[j];
                      sum += nums[x];
                      sum += nums[y];

                    if(sum == target)
                    {
                        vector<int> temp = {nums[i], nums[j], nums[x], nums[y]};
                        ans.push_back(temp);
                        x++;
                        y--;

                        while(x<y && nums[x]==nums[x-1]) x++;
                        while(x<y && nums[y]==nums[y+1]) y--;
                    }

                    else if( sum < target )x++;
                    else y--;
                 }
            }
        }
        return ans;
    }
};