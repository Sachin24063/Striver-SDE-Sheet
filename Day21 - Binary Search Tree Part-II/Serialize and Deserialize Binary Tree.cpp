/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string serialize(TreeNode* root) {
        if(!root) return "";
       queue<TreeNode*> q;
       string s="";
       q.push(root);
       while(!q.empty()){
               TreeNode* temp = q.front();
               q.pop();
               if(temp == NULL) s += "$,";
               else s += to_string(temp->val) + ",";
               if(temp != NULL){
                    q.push(temp->left);
                    q.push(temp->right);
               }
       }
       return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "") return NULL;
        stringstream s(data);
        string str;
        queue<TreeNode*> q;
        getline(s, str,',');
        TreeNode* root = new TreeNode(stoi(str));
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            
            //processing the left subtree
           getline(s, str, ',');
            if(str == "$") temp->left = NULL;
            else{
                TreeNode* temp1 = new TreeNode(stoi(str));
                temp->left = temp1;
                q.push(temp1);
            }
           
           //processing the right subtree
            getline(s, str, ',');
            if(str == "$") temp->right = NULL;
            else{
                TreeNode* temp2 = new TreeNode(stoi(str));
                temp->right = temp2;
                q.push(temp2);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
