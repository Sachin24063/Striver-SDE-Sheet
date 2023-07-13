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
int solve(TreeNode* root){
    if(!root) {
        return 0;
    }
    
    int left_height = 0;
    int right_height = 0;

        left_height = solve(root->left);
        right_height = solve(root->right);
    
    if(left_height == -1 || right_height==-1) return -1;
    if(abs(right_height - left_height) > 1) return -1;

    return 1 + max(left_height, right_height);
}
    bool isBalanced(TreeNode* root) {
        if(solve(root) == -1) return false;
        return true;
    }
};
