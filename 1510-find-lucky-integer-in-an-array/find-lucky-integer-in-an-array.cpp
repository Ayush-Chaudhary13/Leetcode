class Solution {
public:
    int findLucky(vector<int>& arr) {

        unordered_map<int,int> mp;
        int n= arr.size();

        for(int i=0; i<n; i++)
        {
            mp[arr[i]]++;
        }

        int maxi= INT_MIN;

        for(auto it: mp)
        {
           if(it.first==it.second)
           {
             maxi= max(maxi,it.first);
           }
        }
        if(maxi!= INT_MIN) return maxi;

        return -1;
    }
};