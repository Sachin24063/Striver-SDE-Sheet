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
class NodeValue {
public:
    int max_node;
    int min_node;
    int max_sum;
    bool isBST;
};

class Solution {
public:
    NodeValue solve(TreeNode* root, int &ans) {
        if (!root) return {INT_MIN, INT_MAX,  0, true};

        NodeValue left = solve(root->left, ans);
        NodeValue right = solve(root->right, ans);

        NodeValue curr;
        curr.min_node = min(root->val, left.min_node);
        curr.max_node = max(root->val, right.max_node);
        
    if(left.isBST && right.isBST && (left.max_node < root->val) && (right.min_node>root->val)){
        curr.isBST = true;
    }
    else{
        curr.isBST = false;
    }
    curr.max_sum = left.max_sum + right.max_sum + root->val;
    if(curr.isBST){
        ans = max(ans, curr.max_sum);
    }
     return curr;
        }

    int maxSumBST(TreeNode* root) {
        int ans = 0;
        solve(root,ans);
        return ans;
    }
};
