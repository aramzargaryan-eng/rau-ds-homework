#pragma once

struct TreeNode{
    int value;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int val) : value(val), left(nullptr), right(nullptr){}
};

inline void del(TreeNode* root){
    if(root == nullptr){
        return;
    }
    del(root->left);
    del(root->right);

    delete root;
}