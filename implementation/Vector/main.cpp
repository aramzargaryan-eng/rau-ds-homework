#include "Vector.h"
#include <cassert>
#include <iostream>

// Реализуйте методы Vector<T>:
//
//   1. Vector()                        - конструктор по умолчанию
//   2. ~Vector()                       - деструктор
//   3. Vector(const Vector& other)     - конструктор копирования
//   4. operator=(const Vector& other)  - оператор присваивания
//   5. push_back(const T& x)           - добавить в конец
//   6. pop_back()                      - удалить с конца
//   7. operator[](int index)           - доступ по индексу
//   8. back()                          - последний элемент
//   9. insert(int pos, const T& val)   - вставить
//  10. erase(int pos)                  - удалить
//  11. swap(Vector& other)             - обменять содержимое
//  12. clear()                         - очистить
//  13. resize(int new_size)            - изменить размер
//  14. front()                         - первый элемент
//
// Напишите для каждой функции один тест:
//   void test_<название_функции>() { ... }
//
// Каждый тест должен проверять:
//   - Нормальный случай
//   - Граничные случаи


void test_push_back() {
    Vector<int> v;
    
    // Нормальный случай
    v.push_back(5);
    assert(v.size() == 1);
    assert(v[0] == 5);
    
    v.push_back(10);
    v.push_back(15);
    assert(v.size() == 3);
    assert(v.back() == 15);

    assert(v.front() == 5);

    Vector<std::size_t> big;
    for(std::size_t i = 0; i < 1000; ++i){
        big.push_back(i);
    }
    assert(big.size() == 1000);
    assert(big.cap() >= big.size());
    for(std::size_t i = 0; i < 1000; ++i){
        assert(big[i] == i);
    }
    
    v.clear();
    v.push_back(-8);
    assert(v.size() == 1);
    assert(v[0] == -8);

    v.push_back(6);
    v.pop_back();
    v.push_back(67);
    assert(v.size() == 2);
    assert(v.front() == -8);
    assert(v.back() == 67);

    std::cout << "test_push_back passed" << std::endl;
}

// void test_pop_back() { ... }
void test_pop_back(){
    Vector<double> v;
    v.push_back(6.0);
    v.push_back(-7.0);
    v.push_back(6.7);

    assert(v.cap() == 3);

    v.pop_back();
    assert(v.cap() == 3);
    assert(v.size() == 2);
    assert(v[0] == 6.0);
    assert(v.back() == -7);
    v.clear();

    try{
        v.pop_back();
    }
    catch(const std::out_of_range& e){
        assert(std::string(e.what()) == "ara Vector pust");
    }

    v.push_back(6.7);
    assert(v.size() == 1);
    assert(v.back() == v.front() && v.front() == 6.7);

    std::cout << "test_pop_back passed\n";
}
// void test_operator_bracket() { ... }
void test_operator_bracket(){
    Vector<std::string> s;
    s.push_back(std::string("hajox"));
    s.push_back(std::string("Valodik"));

    assert(s[1] == std::string("Valodik"));

    s[0] = std::string("eee");
    assert(s.front() == std::string("eee"));

    std::cout << "test_operator_bracket passed\n"; 
}
// void test_back() { ... }
void test_back(){
    Vector<std::size_t> v;
    v.push_back(1);
    v.push_back(2);
    assert(v.back() == 2);
    v.pop_back();
    assert(v.back() == v.front() && v.back() == v[0]);
    v.pop_back();
    try{
        v.back();
    }
    catch(const std::out_of_range& e){
        assert(std::string(e.what()) == "ara Vector pust");
        
    }
    for(std::size_t i = 0; i < 1000; ++i){
        v.push_back(i);
    }
    assert(v.back() == v[999] && v.back() == 999);
    
    std::cout << "test_back passed\n";
}
// void test_front() { ... }
void test_front(){
    Vector<char> c;
    c.push_back('a');
    c.push_back('b');
    assert(c.front() == c[0] && c.front() == 'a');
    c[0] = 'c';
    assert(c.front() == 'c');
    c.pop_back();
    c.pop_back();
    assert(c.empty());
    try{
        c.front();
    }
    catch(const std::out_of_range& e){
        assert(std::string(e.what()) == "ara Vector pust");
    }
    std::cout << "test_front passed\n";
}
// void test_insert() { ... }
void test_insert(){
    Vector<int> v;
    for(int i = 0; i < 500; ++i){
        v.push_back(i);
    }
    int sixseven = 67;
    v.insert(100, sixseven);
    assert(v.size() == 501);
    assert(v.cap() > v.size());
    assert(v[100] == 67);
    assert(v[101] == 100);
    assert(v.back() == v[500] && v[500] == 499);

    try{
        v.insert(-3, 56);
    }
    catch(const std::out_of_range& e){
        assert(std::string(e.what()) == "znay svoi granici");
    }

    try{
        v.insert(750, 67);
    }
    catch(const std::out_of_range& e){
        std::cout << "     Proverka insert bez assert: " << e.what() << ": opa, oshibka\n";
    }

    std::cout << "test_insert passed\n";
}
// void test_erase() { ... }
void test_erase(){
    Vector<int> v;
    for(int i = 0; i < 250; ++i){
        v.push_back(i);
    }

    assert(v.size() == 250);
    assert(v.back() == 249);
    v.erase(67);
    assert(v[67] == 68);
    assert(v.size() == v.back());
    bool thrown = false;
    try{
        v.erase(-5);
        v.erase(500);
    }
    catch(const std::out_of_range&){
        thrown = true;
    }
    assert(thrown);

    std::cout << "test_erase passed\n";
}
// void test_swap() { ... }
void test_swap(){
    Vector<int> a, b;
    for(int i = 5; i <= 10; ++i){
        a.push_back(i);
    }
    for(int i = 11; i <= 20; ++i){
        b.push_back(i);
    }

    a.swap(b);
    assert(a.size() == 10);
    assert(b.size() == 6);
    for(int i = 0; i < 10; ++i){
        assert(a[i] == 11 + i);
    }
    for(int i = 0; i < b.size(); ++i){
        assert(b[i] == 5 + i);
    }

    a.swap(b);
    a.swap(b);
    assert(a.size() == 10);
    assert(b.size() == 6);
    for(int i = 0; i < 10; ++i){
        assert(a[i] == 11 + i);
    }
    for(int i = 0; i < b.size(); ++i){
        assert(b[i] == 5 + i);
    }
    
    a.clear();
    a.swap(b);
    assert(a.size() == 6);
    assert(b.empty());
    for(int i = 0; i < a.size(); ++i){
        assert(a[i] == 5 + i);
    }
    a.clear();
    b.swap(a);
    assert(a.empty());
    assert(b.empty());
    assert(a.cap() != 0);
    assert(b.cap() != 0);

    std::cout << "test_swap passed\n";
}
// void test_clear() { ... }
void test_clear(){
    Vector<std::size_t> v;
    for(std::size_t i = 0; i < 150; ++i){
        v.push_back(i);
    }
    assert(v.size() == 150);
    assert(v.back() == v[149]);
    v.clear();
    assert(v.empty());
    assert(v.cap() != 0);

    std::cout << "test_clear passed\n";
}
// void test_resize() { ... }
void test_resize(){
    Vector<std::size_t> v;
    for(std::size_t i = 0; i < 100; i += 2){
        v.push_back(i);
    }
    assert(v.size() == 50);

    bool thrown = false;
    try{
        v.resize(-20);
    }
    catch(const std::out_of_range&){
        thrown = true;
    }
    assert(thrown);

    v.resize(100);
    assert(v.size() == v.cap() && v.cap() == 100);

    for(std::size_t i = 50; i < v.size(); ++i){
        assert(v[i] == 0);
    } 

    std::cout << "test_resize passed\n";
}
// void test_copy_constructor() { ... }
void test_copy_constructor(){
    Vector<int> a;
    for(int i = 0; i < 8; ++i){
        a.push_back(i);
    }

    Vector<int> b(a);
    assert(a.size() == b.size() && a.cap() == b.cap());
    for(int i = 0; i < a.size(); ++i){
        assert(a[i] == b[i]);
    }
    //izmenenie kopii na orig ne vliyaet
    b[7] = 99;
    assert(a[7] == 7);
    // izmenenie origa na kopiu ne vliyaet
    a.clear();
    for(int i = 0; i < 7; ++i){
        assert(b[i] == i);
    }
    assert(b.back() == 99);

    std::cout << "test_copy_constructor passed\n";
}
// void test_assignment_operator() { ... }
void test_assignment_operator(){
    Vector<int> a, b;
    for(int i = 0; i < 9; ++i){
        a.push_back(i);
    }

    b.push_back(67);

    b = a;

    assert(a.size() == 9 && a.size() == b.size());
    for(int i = 0; i < b.size(); ++i){
        assert(b[i] == i);
    }

    a.clear();
    b.clear();

    a.push_back(1);
    a.push_back(2);

    b = a;

    b[0] = 67;
    a[1] = -67;

    assert(a.front() == 1 && a.back() == -67);
    assert(b.front() == 67 && b.back() == 2);

    a.clear();

    b = a;
    assert(b.empty()); 

    a.push_back(5);
    a.push_back(6);
    a.push_back(7);

    Vector<int>& c = a;

    a = c;
    assert(a.size() == 3);
    assert(a[0] == 5 && a[1] == 6 && a[2] == 7);

    std::cout << "test_assignment_operator passed\n";
}


int main() {
    std::cout << "Running Vector tests" << std::endl;
    
    test_push_back();
    test_pop_back();
    test_operator_bracket();
    test_back();
    test_front();
    test_insert();
    test_erase();
    test_swap();
    test_clear();
    test_resize();
    test_copy_constructor();
    test_assignment_operator();
    
    std::cout << "All tests passed" << std::endl;
    return 0;
}
