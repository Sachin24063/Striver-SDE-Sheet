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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        q.push(root);
        bool zigzag = true;
        while(!q.empty()){
            int size = q.size();
            vector<int>temp(size);
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                int idx;
                if(zigzag == true){
                    idx = i;
                }
                else{
                    idx = size - 1 - i;
                }
                temp[idx] = node->val;
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            if(zigzag == true) zigzag = false;
            else zigzag = true;
            ans.push_back(temp);
        }
        return ans;
    }
};
