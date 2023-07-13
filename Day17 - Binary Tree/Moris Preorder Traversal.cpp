#include<bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node* left;
    node* right;
};

node* new_node(int data){
    node* newnode = new node;
    newnode->val = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
};


vector<int>  morris_inorder_traversal(node* root){
    vector<int> morris_inorder;
    node* curr = root;
     while(curr != NULL){
         if(curr->left == NULL){
             morris_inorder.push_back(curr->val);
             curr = curr->right;
         }
         else{
             node* prev = curr->left;
             while(prev->right && prev->right != curr){
                 prev = prev->right;
             }
             if(prev->right == NULL){
                 prev->right = curr;
                 morris_inorder.push_back(curr->val);
                 curr = curr->left;
             }
             else{
                prev->right = NULL;
                curr = curr->right;
             }
         }
         
     }
    return morris_inorder;
}

int main(){
    node* root = new_node(1);
    root->left = new_node(2);
    root->right = new_node(3);
    root->left->left = new_node(4);
    root->left->right = new_node(5);
    root->right->left = new_node(6);
    root->right->right = new_node(7);
    
    vector<int> morris_inorder;
   morris_inorder = morris_inorder_traversal(root);
   
   for(int i=0;i<morris_inorder.size();i++){
       cout<<morris_inorder[i]<<" ";
   }
    return 0;
}
