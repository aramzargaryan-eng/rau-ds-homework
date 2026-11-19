#include <iostream>
#include "del.h"

void preorder(TreeNode* root){
    if(root == nullptr){
        return;
    }
    std::cout << root->value << " ";
    preorder(root->left);
    preorder(root->right);
    
}

void inorder(TreeNode* root){
    if(root == nullptr){
        return;
    }
    inorder(root->left);
    std::cout << root->value << " ";
    inorder(root->right);
}

void postorder(TreeNode* root){
    if(root == nullptr){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    std::cout << root->value << " ";
}

int main(){
    std::cout << "github example test:\n";
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    preorder(root);   
    std::cout << '\n';

    inorder(root);    
    std::cout << '\n';

    postorder(root);  
    std::cout << '\n';

    del(root);

    return 0;
}