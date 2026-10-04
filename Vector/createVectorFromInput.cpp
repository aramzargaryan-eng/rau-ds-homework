#include <iostream>
#include <vector>
#include <cassert>

std::vector<int> createVectorFromInput(){
    std::vector<int> vec;
    int n;
    while(true){
        std::cin >> n;
        if(n == 0){
            break;
        }
        vec.push_back(n);
    }
    return vec;
}

void test(){
    std::cout << "Ne znayu, kakoi test tut pisat, no vrode rabotaet" << '\n';
}

int main(){
    std::vector<int> vec = createVectorFromInput();
    std::cout << "Size: " << vec.size() << '\n';
    std::cout << "Elements: ";
    for(int i = 0; i < vec.size(); ++i){
        std::cout << vec[i] << " ";
    }
    std::cout << '\n';
    test();

    return 0;
}