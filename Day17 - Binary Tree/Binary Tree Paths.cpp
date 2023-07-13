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
    void find_path(TreeNode* root, vector<string>&path, string s){
        if(!root->left && !root->right){
            path.push_back(s + to_string(root->val));
        }
        if(root->left != NULL){
            find_path(root->left, path, s+to_string(root->val) + "->");
        }
       if(root->right != NULL){
            find_path(root->right, path, s+to_string(root->val) + "->");
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>path;
        string s = "";
        find_path(root, path, s);
        return path;
    }
};
