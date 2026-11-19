#include <iostream>
#include <cassert>
#include "del.h"

void mirrorTree(TreeNode* root){
    if(root == nullptr){
        return;
    }

    TreeNode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;

    mirrorTree(root->left);
    mirrorTree(root->right);
}

void test(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(-1);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(0);
    root->left->left = new TreeNode(-3);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(5);

    mirrorTree(root);

    assert(root->value == 1);
    assert(root->left->value == 3);
    assert(root->right->value == -1);
    assert(root->left->left->value == 5);
    assert(root->left->right->value == 2);
    assert(root->right->left->value == 0);
    assert(root->right->right->value == -3);

    std::cout << "all test passed\n";
}

int main(){
    std::cout << "Running some tests: ";
    test();

    return 0;
}