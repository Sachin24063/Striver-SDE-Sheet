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

    TreeNode* createTree(vector<int>& preorder, vector<int>& inorder, int prestart, int preend, int instart, int inend, map<int,int>& mp){
        if(prestart > preend || instart > inend) return NULL;
        TreeNode* root = new TreeNode(preorder[prestart]);

        int right_part = mp[root->val];
        int left_part = right_part - instart;

        root->left = createTree(preorder, inorder, prestart+1, prestart+left_part, instart, right_part-1, mp);
        root->right = createTree(preorder, inorder, prestart+left_part+1, preend, right_part+1, inend, mp);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        return createTree(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1, mp);
    }
};
