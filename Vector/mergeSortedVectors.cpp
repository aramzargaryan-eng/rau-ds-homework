#include <iostream>
#include <vector>
#include <cassert>
#include <cstddef>

std::vector<int> mergeSortedVectors(const std::vector<int>& vec1, const std::vector<int>& vec2){
    std::vector<int> vec3;
    std::size_t i = 0, j = 0;
    while(i < vec1.size() && j < vec2.size()){
        if(vec1[i] < vec2[j]){
            vec3.push_back(vec1[i]);
            ++i;
        } else {
            vec3.push_back(vec2[j]);
            ++j;
        }
    }
    // Append any remaining elements from either vector
    while(i < vec1.size()){
        vec3.push_back(vec1[i]);
        ++i;
    }
    while(j < vec2.size()){
        vec3.push_back(vec2[j]);
        ++j;
    }
    return vec3;
}

void print(const std::vector<int>& vec){
    for(std::size_t i = 0; i < vec.size(); ++i){
        std::cout << vec[i] << " ";
    }
    std::cout << '\n';
}

void test(){
    std::vector<int> vec1 = {1, 3, 5};
    std::vector<int> vec2 = {2, 4, 6};
    std::vector<int> vec3 = mergeSortedVectors(vec1, vec2);
    assert(vec3.size() == 6);
    assert(vec3.capacity() >= vec3.size());
    assert(vec3 == std::vector<int>({1, 2, 3, 4, 5, 6}));

    std::vector<int> vec4 = {};
    std::vector<int> vec5 = {4, 5, 6};
    std::vector<int> vec6 = mergeSortedVectors(vec4, vec5);
    assert(vec6 == std::vector<int>({4, 5, 6}));

    std::vector<int> vec7 = {1, 2, 3};
    std::vector<int> vec8 = {};
    std::vector<int> vec9 = mergeSortedVectors(vec7, vec8);
    assert(vec9 == std::vector<int>({1, 2, 3}));

    std::vector<int> vec10 = {};
    std::vector<int> vec11 = {};
    std::vector<int> vec12 = mergeSortedVectors(vec10, vec11);
    assert(vec12.empty());

    std::cout << "All tests passed" << '\n';
}

int main(){
    std::cout << "First vector: ";
    std::vector<int> vec1 = {1, 3, 5};
    print(vec1);
    std::cout << "Second vector: ";
    std::vector<int> vec2 = {2, 4, 6};
    print(vec2);
    std::vector<int> vec3 = mergeSortedVectors(vec1, vec2);
    std::cout << "Merged vector: ";
    print(vec3);
    test();
    return 0;
}