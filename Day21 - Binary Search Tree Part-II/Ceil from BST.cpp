#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

int findCeil(BinaryTreeNode<int> *node, int x){
   BinaryTreeNode<int>* ceil = NULL;
   while(node){
       if(node->data == x){
            return node->data;
       }
       else if(x < node->data){
            ceil = node;
            node = node->left;
       }
       else{
           node = node->right;
       }
   }
    if(ceil) return ceil->data;
    return -1;
}
