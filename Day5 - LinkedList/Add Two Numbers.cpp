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
         ListNode *dummy = new  ListNode();
        ListNode *l = l1, *r = l2, *curr = dummy;
        int carry = 0;
        while(l != NULL || r != NULL){
            int x=0, y=0;
            if(l != NULL) x = l->val;
            if(r != NULL) y = r->val;
            int sum = carry + x + y;
            carry = sum / 10;
            curr->next = new ListNode(sum%10);
            curr = curr->next;
            if(l != NULL) l = l->next;
            if(r != NULL) r = r->next;
            if(carry > 0){
                curr->next = new ListNode(carry);
            }
        }
        return dummy->next;
    }
};
