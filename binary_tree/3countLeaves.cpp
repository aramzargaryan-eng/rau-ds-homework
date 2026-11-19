#include <iostream>
#include <cassert>
#include <cstddef>
#include "del.h"

std::size_t countLeaves(TreeNode* root){
    if(root == nullptr){
        return 0;
    }
    
    if(root->left == nullptr && root->right == nullptr){
        return 1;
    }
    return countLeaves(root->left) + countLeaves(root->right);
}

void test(){
    TreeNode* nol = nullptr;
    assert(countLeaves(nol) == 0);
    del(nol);

    TreeNode* root = new TreeNode(67);
    assert(countLeaves(root) == 1);
    root->left = new TreeNode(-67);
    root->right = new TreeNode(76);
    assert(countLeaves(root) == 2);
    root->left->left = new TreeNode(667);
    root->left->right = new TreeNode(776);
    assert(countLeaves(root) == 3);

    del(root);

    std::cout << "passed\n";
}
int main(){
    std::cout << "github example test: ";
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    std::size_t leaves = countLeaves(root);

    std::cout << leaves << '\n';

    del(root);
    
    std::cout << "Running my test... ";
    test();
    return 0;
}