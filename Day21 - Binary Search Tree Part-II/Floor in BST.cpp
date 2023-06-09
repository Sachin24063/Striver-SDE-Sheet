#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int floorInBST(TreeNode<int> * root, int X)
{
    if(!root) return -1;
    TreeNode<int> * floor;
    while(root){
        if(root->val == X) return root->val;
        else if(X < root->val){
            root = root->left;
        }
        else{
            floor = root;
            root = root->right;
        }
    }
    if(floor != NULL) return floor->val;
    return -1;
}
