#include <iostream>
#include <cassert>
#include <cstddef>
#include "del.h"

std::size_t countNodes(TreeNode* root){
    if(root == nullptr){
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}


void test(){
    TreeNode* nol = nullptr;
    assert(countNodes(nol) == 0);
    del(nol);

    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->left->left = new TreeNode(2);
    root->left->left->left = new TreeNode(3);
    assert(countNodes(root) == 4);
    assert(countNodes(root->left) == 3);

    del(root->left);
    root->left = nullptr;
    assert(countNodes(root) == 1);

    root->right = new TreeNode(1);
    root->right->right = new TreeNode(2);
    root->right->right->right = new TreeNode(3);
    root->right->right->right->right = new TreeNode(4);
    assert(countNodes(root) == 5);
    assert(countNodes(root->right->right) == 3);
    
    root->left = new TreeNode(5);
    root->left->right = new TreeNode(6);
    root->left->right->left = new TreeNode(7);

    assert(countNodes(root->left) == 3);

    del(root);

    std::cout << "my test passed\n";
}

int main(){
    std::cout << "github example test: ";

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    
    std::size_t count = countNodes(root);
    std::cout << count << '\n';

    del(root);

    std::cout << "Running my test... ";
    test();

    return 0;
}