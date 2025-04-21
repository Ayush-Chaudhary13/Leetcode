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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode dummy(0);
        ListNode* curr = &dummy;

        while(p1 && p2) {
            int sum = p1->val + p2->val + carry;
            carry = sum / 10;
            ListNode* new_node = new ListNode(sum % 10);
            curr->next = new_node;
            curr = curr->next;
            p1 = p1->next;
            p2 = p2->next;
        }

        while(p1) {
            int sum = carry + p1->val;
            carry = sum / 10;
            ListNode* new_node = new ListNode(sum % 10);
            curr->next = new_node;
            curr = curr->next;
            p1 = p1->next;
        }
        while(p2) {
            int sum = carry + p2->val;
            carry = sum / 10;
            ListNode* new_node = new ListNode(sum % 10);
            curr->next = new_node;
            curr = curr->next;
            p2 = p2->next;
        }
        if(carry > 0) {
            ListNode* new_node = new ListNode(carry);
            curr->next = new_node;
        }
        return dummy.next;
    }
};