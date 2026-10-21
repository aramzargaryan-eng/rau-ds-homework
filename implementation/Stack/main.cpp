#include "Stack.h"
#include "Test/1default_constructor_test"
#include "Test/2copy_constructor_test"
#include "Test/3assignment_operator_test"
#include "Test/4push_test"
#include "Test/5pop_test"
#include "Test/6top_test"
#include "Test/7size_test"
#include "Test/8capacity_test"
#include "Test/9is_empty_test"
#include "Test/10clear_test"
#include "Test/11peek_test"


// Реализуйте методы Stack<T>:
//   1. Stack()                         - конструктор
//   2. ~Stack()                        - деструктор(Я не знаю, какой тест тут реализовывать)
//   3. Stack(const &)                  - конструктор копирования
//   4. operator=(const &)              - оператор присваивания
//   5. push(const T&)                  - добавить
//   6. pop()                           - удалить
//   7. top()                           - вершина
//   8. size()                          - размер
//   9. capacity()                      - вместимость
//  10. is_empty()                      - пусто ли
//  11. clear()                         - очистить
//  12. peek()                          - просмотреть вершину
//  13. ...
//  14. ...

int main() {
    std::cout << "Running Stack tests" << std::endl;
    default_constructor_test();
    copy_constructor_test();
    assignment_operator_test();
    push_test();
    pop_test();
    top_test();
    size_test();
    capacity_test();
    is_empty_test();
    clear_test();
    peek_test();
    std::cout << "All tests passed" << std::endl;
    return 0;
}
