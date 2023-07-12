/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //if(!head) return head;
        Node *copy = new Node(0);
        Node *curr = head;
        Node *ans = copy;
        unordered_map<Node*, Node*> hash_map;
        while(curr){
            Node *temp = new Node(curr->val);
            hash_map.insert({curr, temp});

            ans->next = temp;
            ans = ans->next;
            curr = curr->next;
        }
         curr =head;
         ans = copy->next;

         while(curr){
             Node *ra = curr->random;
             Node *temp1 = hash_map[ra];
             ans->random = temp1;

             ans = ans->next;
             curr = curr->next;
         }
         return copy->next;
    }
};
