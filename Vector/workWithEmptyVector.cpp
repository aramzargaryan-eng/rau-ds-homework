#include <iostream>
#include <vector>
#include <cassert>

std::vector<int> createAndFillVector(){
    std::vector<int> vec;

    
    for(int i = 0; i < 10; ++i){
        vec.push_back(i + 1);
        
        std::cout << "size: " << vec.size() << '\n';
        std::cout << "capacity: " << vec.capacity() << '\n' << '\n';
    }

    std::cout << "Value: ";
    for(int i = 0; i < 10; ++i){
        std::cout << vec[i] << " ";
    }
    std::cout << '\n';
    return vec;
}

void test(){
    std::vector<int> vec = createAndFillVector();
    assert(vec.size() == 10);
    assert(vec.capacity() >= vec.size());
    for(int i = 0; i < 10; ++i){
        assert(vec[i] == i + 1);
    }

    std::cout << "Test passed" << '\n';
}

int main(){
    test();
    return 0;
}