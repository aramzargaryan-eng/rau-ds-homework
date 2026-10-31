#include <iostream>
#include <forward_list>
#include <cassert>
#include <cstddef>

bool insertAfterPosition(std::forward_list<int>& list, std::size_t pos, int value){
    auto it = list.begin();

    for(std::size_t i = 0; i < pos; ++i){
        if (it == list.end()){
            return false;
        }
        ++it;
    }

    if(it == list.end()){
        return false;
    }

    list.insert_after(it, value);
    return true;
}

void test(){
    std::forward_list<int> f1;
    assert(!insertAfterPosition(f1, 4, -67));

    std::forward_list<int> f2 = {1, 2, 6, 9, -87, 25};
    assert(insertAfterPosition(f2, 3, 38));
    assert(!insertAfterPosition(f2, 10, 23));

    std::cout << "All tests passed \n";
}

int main(){
    std::cout << "github example test: ";
    std::forward_list<int> fl = {1, 2, 3, 4};
    std::cout << insertAfterPosition(fl, 1, 99) << '\n';

    std::cout << "Running my tests... ";
    test();
    return 0;
}