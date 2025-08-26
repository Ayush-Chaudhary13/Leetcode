class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int sum =0;

        for(int i =0; i<nums.size(); i++) {
            int num = nums[i];
            int len =0;
            int maxi = 0;
            while(num) {
                int digit = num%10;
                maxi = max(maxi,digit);
                len++;
                num = num/10;
            }
            num = maxi;
            while(--len) {
                num = num*10+maxi;
            }
            nums[i] = num;
        }
        
        for(auto i: nums) {
            sum += i;
        }
        return sum;
    }
};