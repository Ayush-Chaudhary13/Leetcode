class Solution {
public:
    int compress(vector<char>& chars) {

        string s = "";
        int i =0, n = chars.size();
        int count =0;
	while(i<n)
    { 
        char curr = chars[i];
        count =0;
        
        while(i< n && chars[i] == curr)
        {
            i++;
            count++;
        } 
        s +=  chars[i-1];
        if(count>1)
        s +=  to_string(count); 
    }
    int j =0;
    for(int i =0; i<s.length(); i++)
    {
      chars[j] = s[i];
      j++;
    }

    return s.length();
 }
};