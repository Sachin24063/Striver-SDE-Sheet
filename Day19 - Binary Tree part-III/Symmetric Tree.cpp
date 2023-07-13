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

    bool is_mirror(TreeNode* left, TreeNode* right){
        if(left == NULL || right == NULL){
            return left == right;
        }
        if(left->val != right->val){
            return false;
        }

        return(is_mirror(left->left, right->right)  && is_mirror(left->right, right->left));
        return true;

    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return is_mirror(root->left, root->right);
    }
};
