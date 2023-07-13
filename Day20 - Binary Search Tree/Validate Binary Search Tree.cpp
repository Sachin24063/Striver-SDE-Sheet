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
    bool BSTvalid(TreeNode* root, long long lower_range, long long higher_range){
        if(root == NULL){
            return true;
        }
        if(root->val <= lower_range || root->val >= higher_range){
            return false;
        }
       return (BSTvalid(root->left, lower_range, root->val) && BSTvalid(root->right, root->val, higher_range));
    }
    bool isValidBST(TreeNode* root) {
        return BSTvalid(root, LONG_MIN, LONG_MAX);
    }
};
