#include <bits/stdc++.h> 

bool isLeaf(TreeNode<int>* node) {
    return (node->left == NULL && node->right == NULL);
}
void find_left_boundry(TreeNode<int>* root, vector<int>& ans){
    TreeNode<int>* curr = root->left;
    while(curr){
        if(!isLeaf(curr)) ans.push_back(curr->data);
        if(curr->left) curr = curr->left;
        else curr = curr->right;
    }
}
void find_right_boundry(TreeNode<int>* root, vector<int>& ans){
    stack<int>st;
    TreeNode<int>* curr = root->right;
    while(curr){
        if(!isLeaf(curr)) st.push(curr->data);
        if(curr->right) curr = curr->right;
        else curr = curr->left;
    }
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
}
void find_leaf_node(TreeNode<int>* root, vector<int>& ans){
    if(isLeaf(root)){
        ans.push_back(root->data);
    }
    if(root->left) find_leaf_node(root->left, ans);
    if(root->right) find_leaf_node(root->right, ans);
}
vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int>ans;
    if(!root) return ans;
    if(!isLeaf(root)) ans.push_back(root->data);
    find_left_boundry(root, ans);
    find_leaf_node(root, ans);
    find_right_boundry(root, ans);
    return ans;
}
