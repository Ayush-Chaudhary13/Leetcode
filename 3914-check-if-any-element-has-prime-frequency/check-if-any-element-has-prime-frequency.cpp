class Solution {
public:
    bool isprime(int n)
    {
        if(n == 1) return false;
        if(n ==2) return true;
        for(int i =2; i<=n/2; i++)
        {
            if(n%i ==0) return false;

        }
        return true;
    }
    bool checkPrimeFrequency(vector<int>& nums) {
        
        unordered_map<int,int> mp;

        for(auto it: nums)
        {
            mp[it]++;
        }

        for(auto it: mp)
        {
            cout<<it.first<<"-"<<it.second<<endl;
            if(isprime(it.second))return true;
        }
        return false;
    }
};