#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
int solve(BinaryTreeNode<int>* root) {
  if (!root) {
    return 0;
  }
 int child_sum = 0;
 if(root->left) child_sum += root->left->data;
 if(root->right) child_sum += root->right->data;
    
   if(child_sum >= root->data){
       root->data = child_sum;
   }
   else{
       if(root->left) root->left->data = root->data;
       if(root->right) root->right->data = root->data;
   }
    solve(root->left);
    solve(root->right);

    int total = 0;
    if(root->left) total += root->left->data;
    if(root->right) total+= root->right->data;
    if(root->left || root->right) root->data = total;

}

void changeTree(BinaryTreeNode<int>* root) {
    solve(root);
}
