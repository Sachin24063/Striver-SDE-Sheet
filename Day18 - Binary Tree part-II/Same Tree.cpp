/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

bool identical(TreeNode* p, TreeNode* q){
        if(!p && !q){
            return true;
        }
        if((!p && q) || (p && !q)){
             return false;
        }
        if(p->val != q->val){
            return false;
        }
        if(!identical(p->left, q->left)){
            return false;
        }
        if(!identical(p->right, q->right)){
            return false;
        }
        return true;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return identical(p,q);
    }
};
