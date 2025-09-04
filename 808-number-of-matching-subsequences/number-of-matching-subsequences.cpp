class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> mpp(26);
        for(int i =0; i<s.size(); i++) {
            mpp[s[i] - 'a'].push_back(i);
        }
        int ans=0;
        for(const string& word : words) {
            int curridx = -1;
            bool istrue = true;
            for(char c: word) {
                auto& indices = mpp[c -'a'];
                auto it = upper_bound(indices.begin(), indices.end(), curridx);
                if(it == indices.end()){
                     istrue = false;
                     break;
                 }
                 curridx = *it;
            }
            if(istrue) ans++;
        }
        return ans;
    }
};