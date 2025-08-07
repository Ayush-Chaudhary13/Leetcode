class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";
        stack<char>st;
        st.push(s[0]);
        for(int i =1; i<s.length(); i++)
        {
            if(!st.empty() && s[i] == st.top())
            {
                st.pop();
                continue;
            }
           st.push(s[i]);
        }
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
        
    }
};