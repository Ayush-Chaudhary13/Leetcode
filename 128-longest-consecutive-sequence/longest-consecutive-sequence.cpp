class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> st;
        for(auto x: nums)st.insert(x);
        int best = 0;

        for(auto x: st)
        {
            if(!st.count(x-1))
            {
                int y = x+1;
                while(st.count(y)) y +=1;
                best = max(best,y-x);
            }
        }
        return best;
    }
};