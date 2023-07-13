/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        TreeNode* curr = root;
        while(curr){
        int data = curr->val;
        if(data < p->val && data < q->val){
            curr = curr->right;
        }
        else if(data > p->val && data > q->val){
            curr = curr->left;
        }
        else{
            return curr;
        }
        }
        return curr;
    }
};
