#include <iostream>
#include <forward_list>
#include <stdexcept>
#include <algorithm>
#include <cassert>

void mergeSortedLists(std::forward_list<int>& l1, std::forward_list<int>& l2){
    if(!std::is_sorted(l1.begin(), l1.end()) || !std::is_sorted(l2.begin(), l2.end())){
        throw std::invalid_argument("ara sortiruy spisok");
    }
    
    auto prev = l1.before_begin();
    auto it_1 = l1.begin();
    auto it_2 = l2.begin();

    while(it_1 != l1.end() && it_2 != l2.end()){
        if(*it_2 < *it_1){
            l1.insert_after(prev, *it_2);
            ++prev;
            ++it_2;
        }
        else{
            ++prev;
            ++it_1;
        }
    }
    while(it_2 != l2.end()){
        l1.insert_after(prev, *it_2);
        ++prev;
        ++it_2;
    }
    l2.clear();
}

void test(){
    std::forward_list<int> fl1 = {1, 4, 2, 5, 3, 8};
    std::forward_list<int> fl2 = {1, 3, 4, 6};
    bool thrown = false;
    try{
        mergeSortedLists(fl1, fl2);
    }
    catch(const std::invalid_argument&){
        thrown = true;
    }
    assert(thrown);

    std::forward_list<int> fl3 = {1, 2, 3, 4, 5};
    std::forward_list<int> fl4;
    mergeSortedLists(fl4, fl3);
    assert(fl3.empty());
    assert(fl4 == std::forward_list<int>({1, 2, 3, 4, 5}));

    std::forward_list<int> f5 = {4, 5, 6};
    std::forward_list<int> f6 = {1, 2, 3};
    mergeSortedLists(f5, f6);
    assert(f5 == std::forward_list<int>({1, 2, 3, 4, 5, 6}));
    assert(f6.empty());

    std::forward_list<int> f7 = {1, 2, 3};
    std::forward_list<int> f8 = {4, 5, 6};
    mergeSortedLists(f7, f8);
    assert(f7 == std::forward_list<int>({1, 2, 3, 4, 5, 6}));
    assert(f8.empty());

    std::forward_list<int> f9;
    std::forward_list<int> f10;
    mergeSortedLists(f9, f10);
    assert(f9.empty());
    assert(f10.empty());

    std::cout << "All tests passed\n";
}

int main(){
    std::cout << "github example test: ";
    std::forward_list<int> fl1 = {1, 3, 5};
    std::forward_list<int> fl2 = {2, 4, 6};
    mergeSortedLists(fl1, fl2);
    for(int el : fl1){
        std::cout << el << " ";
    }
    std::cout << '\n';

    std::cout << "Running my tests... ";
    test();

    return 0;
}