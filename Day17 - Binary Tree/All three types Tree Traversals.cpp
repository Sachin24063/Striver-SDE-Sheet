#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/

void traversal(BinaryTreeNode<int> *root, vector<int>&inorder, vector<int>&preorder, vector<int>&postorder){
    if(root == NULL){
        return;
    }
    preorder.push_back(root->data);
    traversal(root->left,inorder,preorder,postorder);
    inorder.push_back(root->data);
    traversal(root->right,inorder,preorder,postorder);
    postorder.push_back(root->data);
}


vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<vector<int>> ans;
    vector<int> inorder, preorder, postorder;
    traversal(root,inorder,preorder,postorder);
    ans.push_back(inorder);
    ans.push_back(preorder);
    ans.push_back(postorder);
    return ans;
}
