class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n,0);

        for(int i=0;i<n; i++) {
            if(k>0) {
                for(int j = i+1; j<= i+k; j++) {
                    ans[i] += code[j%n];
                }
            }
            else if(k<0) {
                for(int j = i-1; j> i-1-abs(k); j--) {
                    ans[i] += code[(j+n)%n];
                }
            }
        }

        return ans;
    }
};