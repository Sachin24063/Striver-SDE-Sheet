/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;
        queue<Node* >q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<Node*> ans;
            for(int i=0;i<size;i++){
                Node* temp = q.front();
                q.pop();
                ans.push_back(temp);

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            if(ans.size() == 2){
                Node* first = ans[0];
                Node* second = ans[1];
                first->next = second;
            }
            else if(ans.size()>2){
                for(int i=0;i<ans.size()-1;i++){
                    Node* first = ans[i];
                    Node* second = ans[i+1];
                    first->next = second;
                }
            }
        }
        return root;
    }
};
