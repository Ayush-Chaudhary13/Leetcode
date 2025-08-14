class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& n1, vector<int>& n2) {
        int s1 = n1.size();
        vector<int> ans(s1,-1);

        for(int i =0; i<s1; i++) {
            for(int j =0; j<n2.size(); j++) {
                if( n2[j] == n1[i]) {
                    bool flag = 0;
                    for(int k = j+1; k<n2.size(); k++) {
                        if(n2[k] > n2[j]) {
                            ans[i] = n2[k];
                            flag =1;
                            break;
                        }
                    }
                    if(flag) break;
                }
            }
        }
        return ans;
    }
};