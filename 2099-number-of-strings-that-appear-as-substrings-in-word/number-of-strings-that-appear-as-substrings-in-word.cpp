class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {

        int count =0;
        for(auto& pattern : patterns)
        {
            if(word.find(pattern) != string::npos) count++;
        }

        return count;  
    }
};