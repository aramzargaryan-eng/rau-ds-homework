#include <iostream>
#include <cassert>
#include "del.h"

int sumNodes(TreeNode* root){
    if(root == nullptr){
        return 0;
    }
    
    return root->value + sumNodes(root->left) + sumNodes(root->right);
}

void test(){
    TreeNode* nol = nullptr;
    assert(sumNodes(nol) == 0);
    delete nol;

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(0);
    assert(sumNodes(root) == 1);
    root->left->left = new TreeNode(-1);
    assert(sumNodes(root) == 0);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(1);
    assert(sumNodes(root) == 3);
    root->right->right = new TreeNode(4);
    root->left->right = new TreeNode(-1);
    assert(sumNodes(root) == 6);
    root->left->right->left = new TreeNode(-73);
    assert(sumNodes(root) == -67);
    
    del(root);

    std::cout << "passed\n";
}

int main(){
    std::cout << "github example test: ";

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    int sum = sumNodes(root);

    std::cout << sum << '\n';
    del(root);

    std::cout << "Running my test... ";
    test();
}