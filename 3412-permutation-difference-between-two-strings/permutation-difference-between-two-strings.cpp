class Solution {
public:
    int findPermutationDifference(string s, string t) {

        int diff =0;
        unordered_map<char, int> mp;
        for(int i =0; i<s.size(); i++)
        {
            mp[s[i]] =i;
        }

        for(int i =0; i<t.size(); i++)
        {
            int idx = mp[t[i]];
            diff += abs(idx - i);
        }
        return diff;
    }
};