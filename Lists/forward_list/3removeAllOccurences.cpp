#include <iostream>
#include <forward_list>
#include <cassert>
#include <iterator>
#include <cstddef>

std::size_t removeAllOccurrences(std::forward_list<int>& list, int value){
    std::size_t rm_count = 0;

    auto prev = list.before_begin();
    while(std::next(prev) != list.end()){
        if(*std::next(prev) == value){
            list.erase_after(prev);
            ++rm_count;
        }
        else{
            ++prev;
        }
    }

    return rm_count;
}

void test(){
    std::forward_list<int> l1;
    std::size_t removed = removeAllOccurrences(l1, 3);
    assert(removed == 0);

    std::forward_list<int> l2 = {1, 2, 2, 2, 4, 56, 2};
    removed = removeAllOccurrences(l2, 2);
    assert(removed == 4);
    assert(!(removed == 0));

    std::cout << "All tests passed\n";
}

int main(){
    std::cout << "github example test: ";
    std::forward_list<int> fl = {1, 2, 3, 2, 4, 2};
    std::size_t removed = removeAllOccurrences(fl, 2);
    std::cout << removed << '\n';

    std::cout << "Running my tests... ";
    test();

    return 0;
}