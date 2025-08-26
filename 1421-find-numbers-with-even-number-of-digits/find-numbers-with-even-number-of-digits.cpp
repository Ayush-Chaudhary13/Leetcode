class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int sum =0;

        for(auto i: nums) {
            int digits =0;
            while(i) {
                i = i/10;
                digits++;
            }
            if(digits%2 == 0) sum++;
        }
        return sum;
        
    }
};