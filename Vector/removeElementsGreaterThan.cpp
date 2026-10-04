#include <iostream>
#include <vector>
#include <cassert>
#include <cstddef>

std::size_t removeElementsGreaterThan(std::vector<int>& vec, int porog){
    std::size_t removedCount = 0;
    while(!vec.empty() && vec.back() > porog){
        vec.pop_back();
        ++removedCount;
    }
    return removedCount;
}

void test(){
    std::vector<int> v = {1, 2, 3, 4, 16, 17, 21, 25, 32};
    std::size_t removedCount = removeElementsGreaterThan(v, 16);
    assert(removedCount == 4);
    assert(v.size() == 5);
    assert(v.capacity() >= v.size());
    assert(v[0] == 1);
    assert(v[1] == 2);
    assert(v[2] == 3);
    assert(v[3] == 4);  
    assert(v[4] == 16);

    std::cout << "Test passed" << '\n';
}

int main(){
    std::vector<int> vec = {1, 3, 6, 7, 67, 76, 711, 911};
    std::size_t removedCount = removeElementsGreaterThan(vec, 76);
    std::cout << "Removed count is: " << removedCount << '\n';
    test();
    return 0;
}
