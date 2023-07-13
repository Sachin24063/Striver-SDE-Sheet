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
    TreeNode* createTree(vector<int>& inorder, vector<int>& postorder, int instart, int inend, int poststart, int postend, map<int,int>& mp){
        if (instart > inend || poststart > postend) return NULL;
        
        TreeNode* root = new TreeNode(postorder[postend]);

        int right_part = mp[root->val];
        int left_part = right_part-instart;

        root->left = createTree(inorder, postorder, instart, right_part-1, poststart, poststart + left_part - 1, mp);
        root->right = createTree(inorder, postorder, right_part+1, inend, poststart + left_part, postend - 1, mp);

        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> mp;
        for (int i=0; i<inorder.size(); i++){
             mp[inorder[i]] = i;
        }
        return createTree(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1, mp);
    }
};
