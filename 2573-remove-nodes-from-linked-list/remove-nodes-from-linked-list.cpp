/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {

        ListNode* curr = head;

        stack<ListNode*> st;
        st.push(curr);
        curr = curr->next;

        while(curr)
        {
            if(curr->val <= st.top()->val) st.push(curr);

            else if( curr->val > st.top()->val)
            {
                while( !st.empty() && curr->val > st.top()->val )
                {
                    st.pop();
                }
               
               if(!st.empty()) st.top()->next = curr;
               st.push(curr);
            }

            curr = curr->next;
        }

        while(st.size() > 1){ st.pop();}

        return st.top();
        
    }
};