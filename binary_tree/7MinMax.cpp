#include <iostream>
#include <cassert>
#include <stdexcept>
#include "del.h"

int findMax(TreeNode* root){
    if(root == nullptr){
        throw std::invalid_argument("tsary meratsa");
    }
    int maxim = root->value;

    if(root->left != nullptr){
        int leftmax = findMax(root->left);
        if(maxim < leftmax){
            maxim = leftmax;
        }
    }

    if(root->right != nullptr){
        int rightmax = findMax(root->right);
        if(maxim < rightmax){
            maxim = rightmax;
        }
    }

    return maxim;
}

int findMin(TreeNode* root){
    if(root == nullptr){
        throw std::invalid_argument("tsary meratsa");
    }
    int minim = root->value;

    if(root->left != nullptr){
        int leftmin = findMin(root->left);
        if(leftmin < minim){
            minim = leftmin;
        }
    }

    if(root->right != nullptr){
        int rightmin = findMin(root->right);
        if(rightmin < minim){
            minim = rightmin;
        }
    }

    return minim;
}

void test(){
    TreeNode* nol = nullptr;
    bool thrown = false;
    try{
        findMax(nol);
    }
    catch(const std::invalid_argument&){
        thrown = true;
    }
    assert(thrown);

    thrown = false;
    try{
        findMin(nol);
    }
    catch(const std::invalid_argument&){
        thrown = true;
    }
    assert(thrown);

    del(nol);

    TreeNode* root = new TreeNode(67);
    assert(findMin(root) == findMax(root));
    root->left = new TreeNode(50);
    root->right = new TreeNode(667);
    root->left->left = new TreeNode(-10);
    root->left->right = new TreeNode(55);
    root->right->right = new TreeNode(911);
    root->right->left = new TreeNode(711);

    assert(findMin(root) == -10);
    assert(findMax(root) == 911);
    
    del(root);
    
    std::cout << "passed\n";
}

int main(){
    std::cout << "github example test:\n";

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(1);

    int maxVal = findMax(root); 
    int minVal = findMin(root);
    
    std::cout << "minimum is " << minVal << '\n';
    std::cout << "maximum is " << maxVal << '\n';

    del(root);

    std::cout << "Running my test... ";
    test();
 
    return 0;
}