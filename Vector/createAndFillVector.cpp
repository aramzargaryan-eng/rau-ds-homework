#include <iostream>
#include <vector>
#include <cassert>

std::vector<int> createAndFillVector(int N){
    std::vector<int> vec(N);
    for(int i = 0; i < N; ++i){
        vec[i] = i + 1;
    }

    std::cout << "Value: ";
    for(int i = 0; i < N; ++i){
        std::cout << vec[i] << " ";
    }
    std::cout << '\n';
    std::cout << "size: " << vec.size() << '\n';
    std::cout << "capacity: " << vec.capacity() << '\n';
    return vec;
}

void test(){
    int N = 6;
    std::vector<int> vec = createAndFillVector(N);
    assert(vec.size() == 6);
    assert(vec.capacity() >= vec.size());
    for(int i = 0; i < N; ++i){
        assert(vec[i] == i + 1);
    }

    std::cout << "Test passed" << '\n';
}

int main(){
    test();
    return 0;
}