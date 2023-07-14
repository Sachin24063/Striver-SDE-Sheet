/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return the Kth largest element in the given BST rooted at 'root'

class Solution
{
    public:
    void solve(Node*root, int&K, int &ans){
        if(!root) return;
        solve(root->right,K, ans);
        K--;
        if(K == 0){ 
            ans = root->data;
            return;
        }
        solve(root->left,K, ans);
    }
    int kthLargest(Node *root, int K)
    {
        int ans;
        solve(root, K, ans);
        return ans;
    }
};
