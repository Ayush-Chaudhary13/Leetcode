class FindSumPairs {
public:
    
    vector<int> v1,v2;
    unordered_map<int,int> m;


    FindSumPairs(vector<int>& nums1, vector<int>& nums2) 
    {
        v1=nums1,v2=nums2;
        sort(v1.begin(), v1.end());

        int n= nums2.size();

        for(int i=0; i<n; i++)
        {
            m[nums2[i]]++;
        }   
    }
    
    void add(int index, int val) 
    {
        m[v2[index]]--;
        v2[index] += val;
        m[v2[index]]++;
        
    }
    
    int count(int tot) 
    {
        int ans=0;
        int n1= v1.size();

        for(int i=0; i<n1; i++)
        {
            if(v1[i]>=tot)break;

            ans += m[tot-v1[i]];
        }

   return ans;
        
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */