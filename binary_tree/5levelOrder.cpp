#include <iostream>
#include <queue>
#include "del.h"

void levelOrder(TreeNode* root){
    if(root == nullptr){
        return;
    }
    std::queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        TreeNode* curr = q.front();
        q.pop();

        std::cout << curr->value << " ";

        if(curr->left != nullptr){
            q.push(curr->left);
        }
        if(curr->right != nullptr){
            q.push(curr->right);
        }
    }
}

int main(){
    std::cout << "github example test: ";
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    levelOrder(root);

    del(root);

    return 0;
}