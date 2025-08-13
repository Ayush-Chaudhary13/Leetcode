class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {

        long long ans=0;
        int i=0, j=nums.size()-1;

        while(i<=j)
        {
            if(i == j) ans+= nums[i];
            else {
            string num = to_string(nums[i]) + to_string(nums[j]);
            ans += stoi(num);
            } 
            i++,j--;
        }
       return ans; 
    }
};