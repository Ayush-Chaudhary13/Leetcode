class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {

        vector<int> prefix(arr.size());
        prefix[0] = arr[0];
        for(int i = 1; i<arr.size(); i++){
            prefix[i] = prefix[i-1]^arr[i];
        }
        vector<int> ans;
        for(auto it: queries){
            int l = it[0];
            int r = it[1];
            if(l == 0) ans.push_back(prefix[r]);
            else ans.push_back(prefix[r] ^ prefix[l-1]);
        }
        return ans;
    }
};