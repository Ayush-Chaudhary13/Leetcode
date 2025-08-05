class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        for(int i=0;i<fruits.size();i++)
            {
                for(int j=0;j<baskets.size();j++)
                    {
                        if(fruits[i]<=baskets[j] && baskets[j]!=0)
                        {
                            baskets[j]=0;
                            break;
                        }
                    }
            }
        int cnt=0;
        for(int b: baskets)
            {
                if(b==0) continue;
                cnt++;
            }
        return cnt;
    }
};