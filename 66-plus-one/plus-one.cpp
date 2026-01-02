class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        int n= digits.size();
        int count=0;
       
        if(digits[n-1]>=0 && digits[n-1]!=9)
        {
            digits[n-1] +=1;
            return digits;
        }


        for(int i=n-1;i>=0;i--)
        {
           
            if(digits[i]!=9)
            {
                digits[i] += 1;
                break;
            }
            else
            {
                digits[i]=0;
                count++;
               
            }
        }

        if(count== n)
        {
            vector<int> ans(n+1,0);
            ans[0]=1;
            return ans;
         }

    
     return digits;   
    }
};