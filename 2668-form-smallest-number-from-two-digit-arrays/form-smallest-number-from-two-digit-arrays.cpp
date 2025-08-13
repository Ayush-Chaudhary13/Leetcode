class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        int n1=9, n2=9;
        vector<int> freq(10,0);
        for(auto i: nums1) {
            if(i<n1) n1=i;
            freq[i]++;
        }
        for(auto i: nums2) {
            if(i<n2) n2=i;
            freq[i]++;
            
        }

        for(int i=1; i<=9; i++)if(freq[i] == 2) return i;

        int nums =0;
        if(n1 > n2) nums = n2*10 +n1;
        else nums = n1*10 + n2;

       return nums; 
    }
};