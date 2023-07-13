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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int, map<int, multiset<int>>> mp;
        queue<pair<TreeNode*, pair<int, int>>> q;  // Store horizontal position as well
        q.push({root, {0, 0}});
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int line = it.second.first;
            int col = it.second.second;
            TreeNode* node = it.first;
            mp[line][col].insert(node->val);
            if (node->left != NULL) {
                q.push({node->left, {line - 1, col + 1}});
            }
            if (node->right != NULL) {
                q.push({node->right, {line + 1, col + 1}});
            }
        }
        for (auto& it : mp) {
            vector<int> level;
            for (auto& col : it.second) {
                for (auto& val : col.second) {
                    level.push_back(val);
                }
            }
            ans.push_back(level);
        }
        return ans;
    }
};
