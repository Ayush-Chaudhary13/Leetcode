class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefix(n);
        prefix[0] = arr[0];

        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] ^ arr[i];
        }

        vector<int> res;
        for(auto &q : queries) {
            int L = q[0], R = q[1];
            if(L == 0) res.push_back(prefix[R]);
            else res.push_back(prefix[R] ^ prefix[L-1]);
        }
        return res;
    }
};