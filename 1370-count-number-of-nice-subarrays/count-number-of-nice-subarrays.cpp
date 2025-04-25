class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
       unordered_map<int,int>mpp;
       int count=0;
       int sum=0;

       for(int i=0;i<nums.size();i++){
        if(nums[i]%2==0){
          sum+=0; 
        }else{
          sum+=1; 
        }
          if(sum==k){
            count++;
          } 
         if(mpp.find(sum-k)!=mpp.end()){
            count+=mpp[sum-k];
         }
         mpp[sum]++;
       }
       return count;
    }
};