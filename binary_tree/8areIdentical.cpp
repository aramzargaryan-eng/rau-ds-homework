#include <iostream>
#include <cassert>
#include "del.h"

bool areIdentical(TreeNode* tree1, TreeNode* tree2){
    if(tree1 == nullptr && tree2 == nullptr){
        return true;
    }
    if(tree1 == nullptr || tree2 == nullptr){
        return false;
    }
    if(tree1->value != tree2->value){
        return false;
    }

    return areIdentical(tree1->left, tree2->left) && areIdentical(tree1->right, tree2->right);
}

void test(){
    TreeNode* root1 = nullptr;
    TreeNode* root2 = nullptr;
    assert(areIdentical(root1, root2));

    root1 = new TreeNode(67);
    root1->left = new TreeNode(667);
    root1->right = new TreeNode(711);

    root2 = new TreeNode(67);
    root2->left = new TreeNode(667);
    root2->right = new TreeNode(711);

    assert(areIdentical(root1, root2));

    root2->left->right = new TreeNode(68);

    assert(!areIdentical(root1, root2));

    root1->left->right = new TreeNode(34);

    assert(!areIdentical(root1, root2));

    del(root1);
    del(root2);

    std::cout << "passed\n";
}

int main(){
    std::cout << "github example test: ";

    TreeNode* tree1 = new TreeNode(1);
    tree1->left = new TreeNode(2);
    tree1->right = new TreeNode(3);

    TreeNode* tree2 = new TreeNode(1);
    tree2->left = new TreeNode(2);
    tree2->right = new TreeNode(3);

    bool identical = areIdentical(tree1, tree2);

    std::cout << identical << '\n';

    del(tree1);
    del(tree2);

    std::cout << "Running my test... ";
    test();

    return 0;
}