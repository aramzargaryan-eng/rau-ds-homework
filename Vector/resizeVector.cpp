#include <iostream>
#include <vector>
#include <cassert>
#include <cstddef>

template<typename T>
void resizeVector(std::vector<T>& vec, std::size_t size, const T& value = T() ){
    for(std::size_t i = 0; i < vec.size(); ++i){
        std::cout << vec[i] << " ";
    }
    std::cout << '\n';

    vec.resize(size, value);

    std::cout << "After resize: ";
    for(std::size_t i = 0; i < vec.size(); ++i){
        std::cout << vec[i] << " ";
    }
    std::cout << '\n' << '\n';
}

void test(){
    std::vector<int> vec = {1, 2, 3};
    std::cout << "Int vector before resize: ";
    resizeVector(vec, 11, -3);
    assert(vec.size() == 11);
    assert(vec.capacity() >= vec.size());
    assert(vec[0] == 1);
    assert(vec[2] == 3);
    for(std::size_t i = 3; i < vec.size(); ++i){
        assert(vec[i] == -3);
    }

    std::vector<double> vec2 = {1.1, 2.2, 3.3};
    std::cout << "Double vector before resize: ";
    resizeVector(vec2, 6, -6.7);
    assert(vec2.size() == 6);
    assert(vec2.capacity() >= vec2.size());
    assert(vec2[0] == 1.1);
    assert(vec2[2] == 3.3);
    for(std::size_t i = 3; i < vec2.size(); ++i){
        assert(vec2[i] == -6.7);
    }

    std::vector<std::string> vec3 = {"dobri", "vecher"};
    std::cout << "String vector before resize: ";
    resizeVector(vec3, 5, std::string("vecher v xatu"));
    assert(vec3.size() == 5);
    assert(vec3.capacity() >= vec3.size());
    assert(vec3[0] == "dobri");
    assert(vec3[1] == "vecher");
    for(std::size_t i = 2; i < vec3.size(); ++i){
        assert(vec3[i] == "vecher v xatu");
    }

    std::vector<char> vec4 = {'a', 'b', 'c'};
    std::cout << "Char vector before resize: ";
    resizeVector(vec4, 7, 'z');
    assert(vec4.size() == 7);
    assert(vec4.capacity() >= vec4.size());
    assert(vec4[0] == 'a');
    assert(vec4[2] == 'c');
    for(std::size_t i = 3; i < vec4.size(); ++i){
        assert(vec4[i] == 'z');
    }

    std::cout << "All tests passed" << '\n';
}

int main(){
    test();

    return 0;
}