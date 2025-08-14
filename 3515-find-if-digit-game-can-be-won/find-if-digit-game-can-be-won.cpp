class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int s =0, d=0;

        for(auto i: nums) {
            if(i>0  && i<10) s +=i;
            else d +=i;
        }
        if(s == d) return 0;

        return 1;
    }
};