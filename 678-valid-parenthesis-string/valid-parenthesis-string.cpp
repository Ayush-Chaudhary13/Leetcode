class Solution {
public:
    bool checkValidString(string s) 
    {
        bool result = true;
        int n= s.size();
        stack<int> left;
        stack<int> astrik;

        for(int i=0; i<n;i++)
        {
            if(s[i]=='(')
            {
                left.push(i);
            }
            else if(s[i]=='*')
            {
                astrik.push(i);
            }    
            else
            {
                if(!left.empty())
                {
                    left.pop();
                }
                else if(!astrik.empty())
                {
                    astrik.pop();
                }   
                else
                {
                    return false;
                }     
            }
      
        }
        while(!astrik.empty() && !left.empty() && left.top() < astrik.top())
        {
            astrik.pop();
            left.pop();
        } 

        if (!left.empty()) {
            return false;
        }

      return result;  
        
    }
};