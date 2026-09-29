#include <iostream>
#include <string>
#include <vector>
#include <cassert>

template <typename T>
int linearSearch(const std::vector<T>& vec, const T& target){
    for(std::size_t i = 0; i < vec.size(); ++i){
        if(vec[i] == target){
            return i;
        }   
    }
    return -1;
}

void linearSearch_test(){
    std::vector<int> vec1 = {1, 2, 3, 50, 60, 67};
    assert(linearSearch(vec1, 67) == 5);
    assert(linearSearch(vec1, 1) == 0);
    assert(linearSearch(vec1, 100) == -1);

    std::vector<double> vec2 = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 6.7};
    assert(linearSearch(vec2, 1.1) == 0);
    assert(linearSearch(vec2, 6.7) == 6);
    assert(linearSearch(vec2, 100.5) == -1);

    std::vector<std::string> vec3 = {"baylus", "вечер", "в", "хату", "dzez"};
    assert(linearSearch(vec3, std::string("baylus")) == 0);
    assert(linearSearch(vec3, std::string("dzez")) == 4);
    assert(linearSearch(vec3, std::string("Hello World!")) == -1);
 
}

int main(){
    linearSearch_test();
    std::cout << "All tests passed!" << '\n';
    return 0;
}