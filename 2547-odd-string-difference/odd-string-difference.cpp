class Solution {
public:
    bool help(string a, string b)
    {
        for(int i =1; i<a.size(); i++)
        {
            if((a[i] - a[i-1]) !=  (b[i]-b[i-1]) ) return false;
        }
        return true;   

    }
    string oddString(vector<string>& words) {

        int index=0, match=0;

        for(int i =1; i< words.size(); i++)
        {
            if(help(words[i], words[0])) match++;

            else index = i;
        }

        return match > 0 ? words[index] : words[0];    
    }
};