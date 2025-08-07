class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int i=0,sz= min(min(s1.size(),s2.size()),s3.size());
        while(i< sz && s1[i]==s2[i] && s2[i]==s3[i]) i++;

        return i==0 ? -1 : s1.size()+s2.size()+s3.size()-i*3;
        
    }
};