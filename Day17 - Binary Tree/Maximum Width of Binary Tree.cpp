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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        int width = 0;
        queue<pair<TreeNode*,long long>>q;
            q.push({root, 0});
        while(!q.empty()){
            int size = q.size();
            int min_level = q.front().second;
            int first, last;
            for(int i=0;i<size;i++){
            long long curr_index = q.front().second - min_level;
            TreeNode* node = q.front().first;
            q.pop();
            if(i==0) first = curr_index;
            if(i == size-1) last = curr_index;
            if(node->left){
                q.push({node->left,curr_index*2+1});
            } 
            if(node->right){
                q.push({node->right,curr_index*2+2});
            }   
            }
            width = max(width, last-first+1);
        }
        return width;
    }
};
