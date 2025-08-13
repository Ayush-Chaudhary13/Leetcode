class Solution {
public:
    int minimumSum(vector<int>& nums) {

        int sum = INT_MAX, n = nums.size();

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
               for(int k=j+1;k<n;k++){
                    if((nums[i]<nums[j]) && (nums[k]<nums[j])){
                         sum=min(sum, (nums[i]+nums[j]+nums[k]));
                    }
               } 
           }      
        }
        if(sum !=INT_MAX) return sum;

        return -1;
    }
};