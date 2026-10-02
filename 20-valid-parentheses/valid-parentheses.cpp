class Solution {
public:
    bool isValid(string s)
    {
        stack<char> q;
        for(char ch:s)
        {
            if(ch=='{' || ch=='(' || ch=='[') {q.push(ch);}
            else
            {
                if(q.empty()) return false;
                else
                {
                    char top= q.top();
                    if((ch=='}' && top=='{') || (ch==')' && top=='(') || (ch==']' && top=='['))
                    {  q.pop(); }
                    else {return false;}
                }
            }
        }
         if(q.empty()) return true;
         return false;
       }
};