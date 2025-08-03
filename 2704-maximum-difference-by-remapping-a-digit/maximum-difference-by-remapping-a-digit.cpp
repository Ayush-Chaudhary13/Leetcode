class Solution {
public:
    int minMaxDifference(int num) {

        string str = to_string(num);
        string max = "";
        string min = "";
        char ch;

        for(int i =0; i<str.size(); i++)
        {
            if(str[i] != '9')
            {
                ch = str[i];   
                break;  
            }
        }
         
        for(int i =0; i<str.size(); i++)
         {
            if(str[i] == ch)
             {
               max += '9';
             }
            else
            {
              max += str[i];
            }
                    
        }

        ch = str[0];

        for(int i = 0; i <str.size(); i++)
        {
            if(str[i] == ch)
            {
                min += '0';
            }
            else
            {
                min += str[i];
            }
        }
     return stoi(max) - stoi(min);
   }
};