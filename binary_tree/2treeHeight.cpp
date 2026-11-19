#include <iostream>
#include <cstddef>
#include <cassert>
#include "del.h"

std::size_t treeHeight(TreeNode* root){
    if(root == nullptr){
        return 0;
    }
    std::size_t leftH = treeHeight(root->left);
    std::size_t rightH = treeHeight(root->right);

    if(leftH < rightH){
        return 1 + rightH;
    }
    else{
        return 1 + leftH;
    }
}

void test(){
    TreeNode* nol = nullptr;
    assert(treeHeight(nol) == 0);
    del(nol);

    TreeNode* root = new TreeNode(1);
    assert(treeHeight(root) == 1);
    root->left = new TreeNode(-2);
    root->right = new TreeNode(2);
    assert(treeHeight(root) == 2);
    root->left->left = new TreeNode(-3);
    assert(treeHeight(root) == 3);
    root->left->right = new TreeNode(-4);
    root->left->right->left = new TreeNode(-5);
    root->left->right->left->right = new TreeNode(-6);
    assert(treeHeight(root->left) == 4);
    assert(treeHeight(root->left->right) > treeHeight(root->right));

    del(root);
    
    std::cout << "passed\n";
}
int main(){
    std::cout << "github example test: ";

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);  
    root->left->left = new TreeNode(4);

    std::size_t height = treeHeight(root);

    std::cout << height << '\n';

    del(root);

    std::cout << "Running my test... ";
    test();

    return 0;
}