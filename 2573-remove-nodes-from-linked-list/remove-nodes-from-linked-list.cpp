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

Solution() {
      
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }

    ListNode* removeNodes(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head ;
        }
      ListNode* next = removeNodes(head->next);
      if(next->val > head->val){
        return next ;
      }  
      head->next = next ;
      return head ;
    }
};