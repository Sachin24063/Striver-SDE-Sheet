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

   int solve(TreeNode* root, int &max_sum){
        if(!root){
            return 0;
        }
        int left_sum = max(0, solve(root->left, max_sum));
        int right_sum = max(0, solve(root->right, max_sum));

        max_sum = max(max_sum, left_sum + right_sum + root->val);
        return root->val + max(left_sum, right_sum);
    }

    int maxPathSum(TreeNode* root) {
        int max_sum = INT_MIN;
        solve(root, max_sum);
        return max_sum;
    }
};
