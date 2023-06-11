/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1=0,l2=0;
        ListNode *dummy = headA;
        while(dummy){
            l1++;
            dummy = dummy->next;
        }
        dummy = headB;
        while(dummy){
            l2++;
            dummy = dummy->next;
        }
        int diff = abs(l1-l2);
        if(l1<l2){
            while(diff--){
                headB = headB->next;
            }
        }
        else{
            while(diff--){
                headA = headA->next;
            }
        }
        while(headA && headB){
            if(headA == headB) {return headA;}
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};
