class Solution {
public:
     void generate(int open, int closed, string s, vector<string> &ans){
        if(open == 0 && closed == 0){
            ans.push_back(s);
            return;
        }

        if(open>0){
          generate(open-1,closed, s+'(',ans);
        }
        if(closed>0 && closed>open){
         generate(open, closed-1, s+')', ans);
        
        }
    }
    vector<string> generateParenthesis(int n) 
    {  
        vector<string> ans;
        string s="(";
        int open = n-1;
        int closed = n;
        generate(open, closed, s, ans); 
        return ans;
        
    }
};