#include "ForwardList.h"
#include <cassert>
#include <iostream>

// Реализуйте методы ForwardList<T>:
//   1. ForwardList()                   - конструктор
//   2. ~ForwardList()                  - деструктор
//   3. ForwardList(const &)            - конструктор копирования
//   4. operator=(const &)              - оператор присваивания
//   5. push_front(const T&)            - добавить в начало
//   6. pop_front()                     - удалить с начала
//   7. front()                         - первый элемент
//   8. insert_after(Node*, const T&)   - вставить после узла
//   9. erase_after(Node*)              - удалить после узла
//  10. clear()                         - очистить
//  11. reverse()                       - развернуть
//  12. size()                          - размер
//  13. empty()                         - пусто ли
//  14. begin()                         - начало списка

//default constructor test
void test_default_constructor(){
    ForwardList<double> list;
    assert(list.size() == 0);
    assert(list.empty());
    assert(list.begin() == nullptr);

    std::cout << "test_default_constructor passed\n";
}

// copy constructor test
void test_copy_constructor(){
    ForwardList<char> a;
    a.push_front('c');
    a.push_front('b');
    a.push_front('a');
    ForwardList<char> b(a);
    assert(a.size() == 3 && a.size() == b.size());
    assert(a.front() == 'a' && a.front() == b.front());
    assert(b.begin()->data == 'a');
    assert(a.begin()->next->data == 'b');
    assert(b.begin()->next->next->data == 'c');

    a.pop_front();
    a.push_front('d');
    assert(b.front() == 'a');

    b.pop_front();
    assert(a.size() == 3);
    assert(a.front() == 'd');

    a.clear();

    ForwardList<char> c(a);
    assert(a.empty());
    assert(c.empty());
    assert(c.begin() == nullptr); 

    std::cout << "test_copy_constructor passed\n";
}
//operator= test
void test_assignment(){
    ForwardList<int> a;
    a.push_front(3);
    a.push_front(9); 

    ForwardList<int> b;
    b.push_front(2);
    b.push_front(4);
    b.push_front(8);

    a = b;

    assert(a.size() == 3);
    assert(a.begin()->data == 8);
    assert(a.begin()!= b.begin());

    ForwardList<int> c;
    a = c;
    assert(a.empty());
    
    b = b;
    assert(b.size() == 3);
    assert(b.front() == 8);

    std::cout << "test_assignment passed\n";
}

//push_front test
void test_push_front() {
    ForwardList<int> list;
    
    list.push_front(1);
    assert(list.size() == 1);
    assert(list.front() == 1);
    
    list.push_front(2);
    list.push_front(3);
    assert(list.size() == 3);
    assert(list.front() == 3);
    assert(!list.empty());
    
    std::cout << "test_push_front passed" << std::endl;
}


// void test_pop_front() { ... }
void test_pop_front(){

    ForwardList<int> list;

    bool thrown = false;
    try{
        list.pop_front();
    }
    catch(const std::out_of_range&){
        thrown = true;
    }
    assert(thrown);

    for(int i = 8; i >= 0; --i){
        list.push_front(i);
    }
    assert(list.size() == 9);
    assert(list.begin()->data == 0);

    list.pop_front();
    assert(list.size() == 8);
    assert(list.begin()->data == 1);

    int i = 1;
    while (i <= 3){
        list.pop_front();
        ++i;
    }
    assert(list.size() == 5);
    assert(list.begin()->data == 4);

    std::cout << "test_pop_front passed\n";
}
// void test_front() { ... }
void test_front(){
    ForwardList<int> list;
    bool thrown = false;
    try{
        list.front();
    }
    catch(const std::out_of_range&){
        thrown = true;
    }
    assert(thrown);

    list.push_front(1);
    assert(list.front() == 1);

    list.push_front(6);
    list.push_front(67);
    list.push_front(7);

    assert(list.front() == 7);
    list.pop_front();
    assert(list.front() == 67);

    std::cout << "test_front passed\n";
}

//insert after test
void test_insert_after(){
    ForwardList<int> list;
    bool thrown = false;
    try{
        (list.insert_after(nullptr, 1));
    }
    catch(const std::invalid_argument&){
        thrown = true;
    }    
    assert(thrown);
    
    list.push_front(67);
    list.insert_after(list.begin(), 33);
    assert(list.size() == 2);
    assert(list.begin()->data == 67);
    assert(list.begin()->next->data == 33);
    assert(list.begin()->next->next == nullptr);

    std::cout << "test_insert_after passed\n";
}

void test_erase_after(){
    ForwardList<double> a;

    a.push_front(6.7);
    bool thrown = false;
    try{
        a.erase_after(nullptr);
    }
    catch(const std::invalid_argument&){
        thrown = true;
    }
    assert(thrown);

    thrown = false;
    try{
        a.erase_after(a.begin());
    }
    catch(const std::invalid_argument&){
        thrown = true;
    }
    assert(thrown);

    a.push_front(-6.7);
    a.push_front(7.6);
    a.push_front(7.11);
    
    a.erase_after(a.begin()->next);
    assert(a.begin()->next->data == 7.6);

    std::cout << "test_erase_after passed\n";
}

void test_clear(){
    ForwardList<int> list;
    for(int i = 10; i > 0; --i){
        list.push_front(i);
    }
    assert(list.size() == 10);

    list.clear();
    assert(list.size() == 0);

    std::cout << "test_clear passed\n";
}

void test_reverse(){
    ForwardList<int> list;

    for(int i = 4; i > 0; --i){
        list.push_front(i);
    }
    assert(list.front() == 1);
    assert(list.begin()->next->data == 2);
    assert(list.begin()->next->next->data == 3);
    assert(list.begin()->next->next->next->data == 4);

    list.reverse();

    assert(list.front() == 4);
    assert(list.begin()->next->data == 3);
    assert(list.begin()->next->next->data == 2);
    assert(list.begin()->next->next->next->data == 1);

    std::cout << "test_reverse passed\n";
}

void test_size(){
    ForwardList<int> a;
    assert(a.size() == 0);

    for(int i = 1000; i > 0; --i){
        a.push_front(i);
    }
    assert(a.size() == 1000);

    std::cout << "test_size passed\n";
}

void test_empty(){
    ForwardList<double> b;
    assert(b.empty());
    b.push_front(6.7);
    assert(!b.empty());

    std::cout << "test_empty passed\n";
}

void test_begin(){
    ForwardList<int> a;
    const ForwardList<int>& b = a;

    assert(a.begin() == nullptr);
    assert(b.begin() == nullptr);

    a.push_front(67);
    assert(a.begin()->data == 67);
    assert(b.begin()->data == 67);

    a.push_front(-67);
    assert(a.begin()->next->data == 67);
    assert(b.begin()->next->data == 67);

    assert(a.begin() == b.begin());

    a.begin()->data = 711;
    assert(b.begin()->data == 711);

    std::cout << "test_begin passed\n";

}

int main() {
    std::cout << "Running ForwardList tests" << std::endl;
    test_push_front();
    test_default_constructor();
    test_copy_constructor();
    test_assignment();
    test_pop_front();
    test_front();
    test_insert_after();
    test_erase_after();
    test_clear();
    test_reverse();
    test_size();
    test_empty();
    test_begin();

    std::cout << "All tests passed" << std::endl;
    return 0;
}
