class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) 
{
	sort(nums.begin(), nums.end());
	int i=0,j=1,ans = 1;
    long long  diff = 0;
	while(j <nums.size( ))
	{             
		long long count = j-i;  		
		diff +=  count*(nums[j]-nums[j-1]);
 		if( diff > k) {
			while(diff>k)
			{
			    diff -= nums[j] - nums[i];
			  i++;
			}
		}
		ans = max(ans, (j-i+1));
        j++;
	}    
      return ans;  
 }
};