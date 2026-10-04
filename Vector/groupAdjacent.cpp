#include <iostream>
#include <vector>
#include <cassert>
#include <cstddef>

std::vector<std::vector<int>> groupAdjacent(const std::vector<int>& vec){
    std::vector<std::vector<int>> result;
    if(vec.empty()){
        return result;
    }

    std::vector<int> curr_gr;
    curr_gr.push_back(vec[0]);
    for(std::size_t i = 1; i < vec.size(); ++i){
        if(vec[i] == vec[i - 1]){
            curr_gr.push_back(vec[i]);
        }
        else{
            result.push_back(curr_gr);
            curr_gr.clear();
            curr_gr.push_back(vec[i]);
        }
    }
    result.push_back(curr_gr);
    return result;
}

void print(const std::vector<std::vector<int>>& vec){
    std::cout << "{ ";
    for(std::size_t i = 0; i < vec.size(); ++i){
        std::cout << "{";
        for(std::size_t j = 0; j < vec[i].size(); ++j){
            std::cout << vec[i][j];
            if(j < vec[i].size() - 1){
                std::cout << ", ";
            }
        }
        if(i < vec.size() - 1){
            std::cout << "}, ";
        }
        else{
            std::cout << "}";
        }
    }
    std::cout << " }" << '\n';
}

void test(){
    std::vector<int> vec1 = {1, 1, 2, 3, 3, 3, 4, 4, 5};
    std::vector<std::vector<int>> expected1 = {{1, 1}, {2}, {3, 3, 3}, {4, 4}, {5}};
    assert(groupAdjacent(vec1) == expected1);

    std::vector<int> vec2 = {};
    std::vector<std::vector<int>> expected2 = {};
    assert(groupAdjacent(vec2) == expected2);

    std::vector<int> vec3 = {1};
    std::vector<std::vector<int>> expected3 = {{1}};
    assert(groupAdjacent(vec3) == expected3);

    std::vector<int> vec4 = {1, 2, 3};
    std::vector<std::vector<int>> expected4 = {{1}, {2}, {3}};
    assert(groupAdjacent(vec4) == expected4);

    std::cout << "All tests passed!" << '\n';
}

int main(){
    std::vector<int> vec = {1, 1, 2, 3, 3, 3, 4, 4, 5};
    std::vector<std::vector<int>> grouped = groupAdjacent(vec);
    print(grouped);
    test();
    return 0;
}