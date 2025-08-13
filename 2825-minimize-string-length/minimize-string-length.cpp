class Solution {
public:
    int minimizedStringLength(string s) {
        string p="";
        sort(s.begin(),s.end());
        p += s[0];
        cout<<p<<endl;
        for(int i =1; i<s.size(); i++)
        {
            if(s[i] == s[i-1]) continue;
            else p+= s[i];
        }
        cout<<p;
       return p.size(); 
        
    }
};