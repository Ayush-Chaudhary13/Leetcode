class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int maxprofit= 0,i=0;
        int minval= INT_MAX;

        while(i<prices.size())
        {
            minval= min( minval, prices[i]);

            if(prices[i]>=minval)
            {
                maxprofit= max(maxprofit,prices[i]-minval);
            }
            i++;
        }
        return maxprofit;

        
    }
};