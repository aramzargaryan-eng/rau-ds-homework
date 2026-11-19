#include <iostream>
#include <cassert>
#include <cstddef>
#include "del.h"

std::size_t countNodesAtDepth(TreeNode* root, std::size_t k){
    if(root == nullptr || k == 0){
        return 0;
    }
    if(k == 1){
        return 1;
    }
    return countNodesAtDepth(root->left, k - 1) + countNodesAtDepth(root->right, k - 1);
}

void test(){
    TreeNode* root = nullptr;
    assert(countNodesAtDepth(root, 0) == 0);
    assert(countNodesAtDepth(root, 47) == 0);

    root = new TreeNode(1);
    assert(countNodesAtDepth(root, 1) == 1);
    assert(countNodesAtDepth(root, 2) == 0);
    assert(countNodesAtDepth(root, 0) == 0);

    root->left = new TreeNode(2);
    assert(countNodesAtDepth(root, 2) == 1);
    root->right = new TreeNode(3);
    assert(countNodesAtDepth(root, 2) == 2);
    root->right->right = new TreeNode(67);
    assert(countNodesAtDepth(root, 3) == 1);
    root->right->left = new TreeNode(-67);
    assert(countNodesAtDepth(root, 3) == 2);
    root->left->left = new TreeNode(78);
    assert(countNodesAtDepth(root, 3) == 3);
    
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

    std::size_t count = countNodesAtDepth(root, 3);
    std::cout << count << '\n';

    del(root);

    std::cout << "Running my test... ";
    test(); 

    return 0;
}