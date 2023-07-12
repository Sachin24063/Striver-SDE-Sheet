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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL ) return NULL;
        if(k ==0 || head->next == NULL) return head;
        ListNode *curr = head;
        int len = 0;
        while(curr->next != NULL){
            len ++;
            curr = curr->next;
        }
        len++;
        curr->next = head;
        int rotate_pts = len - k % len;
        curr = head;
        while(rotate_pts > 1){
            curr = curr->next;
            rotate_pts--;
        }
        head = curr->next;
        curr->next = NULL;
        return head;
    }
};
