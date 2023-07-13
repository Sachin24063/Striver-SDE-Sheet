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
    int height_tree(TreeNode* root, int height){
        if(!root) return 0;
        int height1 = height_tree(root->left, height);
        int height2 = height_tree(root->right, height);
        
        return max(height1, height2)+1;
    }
    int maxDepth(TreeNode* root) {
        int height = height_tree(root,0);
        return height;
    }
};
