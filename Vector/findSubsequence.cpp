#include <iostream>
#include <vector>
#include <cassert>
#include <cstddef>

int findSubsequence(const std::vector<int>& main_vec, const std::vector<int>& sub_vec){
    if(sub_vec.empty()){
        return 0;
    }

    if(main_vec.size() < sub_vec.size()){
        return -1;
    }

    for(int i = 0; i <= main_vec.size() - sub_vec.size(); ++i){
        bool found = true;
        for(int j = 0; j < sub_vec.size(); ++j){
            if(main_vec[i + j] != sub_vec[j]){
                found = false;
                break;
            }
        }
        if(found){
            return i;
        }
    }
    return -1;
}

void test(){
    std::vector<int> main_vec = {1, 2, 3, 4, 5};
    std::vector<int> sub_vec1 = {2, 3};
    std::vector<int> sub_vec2 = {4, 5};
    std::vector<int> sub_vec3 = {6, 7};
    std::vector<int> sub_vec4 = {};
    std::vector<int> sub_vec5 = {1, 2, 3, 4, 5, 6};
    std::vector<int> sub_vec6 = {1, 2, 3, 4, 5};
    std::vector<int> sub_vec7 = {5, 4, 3, 2, 1};

    assert(findSubsequence(main_vec, sub_vec1) == 1);
    assert(findSubsequence(main_vec, sub_vec2) == 3);
    assert(findSubsequence(main_vec, sub_vec3) == -1);
    assert(findSubsequence(main_vec, sub_vec4) == 0);
    assert(findSubsequence(main_vec, sub_vec5) == -1);
    assert(findSubsequence(main_vec, sub_vec6) == 0);
    assert(findSubsequence(main_vec, sub_vec7) == -1);
    
    std::cout << "All tests passed!" << '\n';
}

int main(){
    std::vector<int> main_vec = {1, 2, 3, 4, 5};
    std::vector<int> sub_vec = {4, 5};
    std::cout << findSubsequence(main_vec, sub_vec) << '\n';
    test();
    return 0;
}