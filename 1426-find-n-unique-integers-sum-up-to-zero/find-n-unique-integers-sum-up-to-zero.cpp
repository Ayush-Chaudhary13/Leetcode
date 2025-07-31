class Solution {
public:
    vector<int> sumZero(int n) {

        vector<int> ans(n,0);
        if(n ==1) return ans;
        int k =1;

        for(int i =0; i<n && i+1 < n; i+=2)
        {
            ans[i] =k;
            ans[i+1] = -k;
            k++;
        }
        

        return ans;
        
    }
};