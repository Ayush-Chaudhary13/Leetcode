class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {

         vector<string>ans;
         if(nums.empty()) return ans;

         int start = nums[0];
         int prev= nums[0];
        
        for(int i =1; i< nums.size(); i++)
        {
            if(nums[i] == prev + 1) prev = nums[i];

            else
            {
                if(start == prev) ans.push_back(to_string(start));

                else
                {
                    ans.push_back(to_string(start) + "->" + to_string(prev));
                }

                start = nums[i];
                prev = nums[i];
            }
            
        } 

         if (start == prev) {
            ans.push_back(to_string(start));
        } else {
            ans.push_back(to_string(start) + "->" + to_string(prev));
        }
        return ans;     
    }
};