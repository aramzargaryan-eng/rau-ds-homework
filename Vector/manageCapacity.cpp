#include <iostream>
#include <vector>
#include <cassert>

void manageCapacity(std::vector<int>& vec){
    std::cout << "Size before reserve: " << vec.size() << '\n';
    std::cout << "Capacity before reserve: " << vec.capacity() << '\n';

    vec.reserve(500);

    std::cout << "Size after reserve: " << vec.size() << '\n';
    std::cout << "Capacity after reserve: " << vec.capacity() << '\n';

    for(int i = 1; i <= 500; ++i){
        vec.push_back(i);
    }

    std::cout << "Size after push_back: " << vec.size() << '\n';
    std::cout << "Capacity after push_back: " << vec.capacity() << '\n';
}

void test(){
    std::vector<int> vec;
    manageCapacity(vec);
    assert(vec.size() == 500);
    assert(vec.capacity() >= vec.size());
    for(int i = 0; i < 500; ++i){
        assert(vec[i] == i + 1);
    }

    std::cout << "Test passed" << '\n';
}

int main(){
    test();
    return 0;
}