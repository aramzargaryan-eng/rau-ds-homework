#include <iostream>
#include <cassert>
#include <stdexcept>
#include <forward_list>

void createAndFillList(const int& N){
    std::forward_list<int> list;

    if(N <= 0){
        throw std::invalid_argument("list i tak pust ara");
    }

    for(int i = 1; i <= N; ++i){
        list.push_front(i);
    }

    std::cout << "Create and fill list for " << N << " is { ";
    for(auto el : list){
        std::cout << el << " ";
    }
    std::cout << "}\n";
}

void test(){
    bool thrown = false;
    try{
        createAndFillList(0);
    }
    catch(const std::invalid_argument&){
        thrown = true;
    }
    assert(thrown);

    std::cout << "Exception test passed\n"; 
}

int main(){
    createAndFillList(5);
    test();
    return 0;
}