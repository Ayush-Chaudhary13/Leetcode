class Solution {
public:
    bool isPowerOfFour(int n) {

        for(int i=0; i<=15; i++)
        {
            int pow4= pow(4,i);
            if(pow4 == n) return true;
            if(pow4 >n) return false;
        }
        return false;
    }
};