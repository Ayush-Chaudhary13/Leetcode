class Solution {
public:
    int findPermutationDifference(string s, string t) {

        int diff =0;
        for(int i =0; i<s.size(); i++)
        {
            char ch = s[i];
            int j = t.find(ch);
            diff += abs(j-i);
        }
        return diff;
    }
};