/* BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively

class Solution
{
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        pre = NULL;
        suc = NULL;
        Node* curr = root;
        while(curr){
            if(curr->key == key){
                if(curr->left){
                    pre = curr->left;
                    while(pre->right) pre = pre->right;
                }
                if(curr->right){
                    suc = curr->right;
                    while(suc->left) suc = suc->left;
                }
                break;
            } 
            else if(key < curr->key){
                suc = curr;
                curr = curr->left;
            }
            else{
                pre = curr;
                curr = curr->right;
            }
        }
    }
};
