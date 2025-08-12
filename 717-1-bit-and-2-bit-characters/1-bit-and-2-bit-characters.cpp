class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n =bits.size(), c=0;
        for(int i =n-2; i>=0; i--)
        {
            if(bits[i] == 1)c++;
            else break;
        }
       return !(c%2); 
    }
};