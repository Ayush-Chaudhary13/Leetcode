class Solution {
public:
    bool halvesAreAlike(string s) {

        int n= s.size(), a=0,b=0;

        for(int i =0; i<n/2; i++)
        {
            char cha = tolower(s[i]);
        if(cha == 'a' || cha == 'A' || cha == 'e' || cha == 'E' ||
           cha == 'i' || cha == 'I' || cha == 'o' || cha == 'O' ||
           cha == 'u' || cha == 'U'  ) a++;

           char chb = tolower(s[i+n/2]);
           if(chb == 'a' || chb == 'A' || chb == 'e' || chb == 'E' ||
           chb == 'i' || chb == 'I' || chb == 'o' || chb == 'O' ||
           chb == 'u' || chb == 'U' ) b++; 
        }
        return a==b;
        
    }
};