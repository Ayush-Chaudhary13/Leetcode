class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success)
     {
         int m= potions.size();
         vector<int> pairs;
         sort(potions.begin(),potions.end());


         for(auto i: spells)
         {
             int low=0;
             int high= m-1;
            
           while(low<=high)
             {
                 int mid = (low+high)/2;

                 if(success>1ll*i*potions[mid])
                 {
                     low= mid+1;
    
                 }
                 else
                 {
                     high=mid-1;
                 }

             }
             pairs.push_back(m-low);

         }
         return pairs;
        
     }
};