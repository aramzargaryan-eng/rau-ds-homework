#include "BinarySearchTree.h"
#include "Test/1.default_constructor_test"
#include "Test/2.copy_constructor_test"
#include "Test/3.assignement_operator_test"
#include "Test/4.insert_test"
#include "Test/5.remove_test"
#include "Test/6.find_test"
#include "Test/7.inorder_test"
#include "Test/8.preorder_test"
#include "Test/9.postorder_test"
#include "Test/10.size_test"
#include "Test/11.height_test"
#include "Test/12.clear_test"
#include "Test/13.is_empty_test"

// Реализуйте методы BinarySearchTree<T>:
//   1. BinarySearchTree()              - конструктор
//   2. ~BinarySearchTree()             - деструктор
//   3. BinarySearchTree(const &)       - конструктор копирования
//   4. operator=(const &)              - оператор присваивания
//   5. insert(const T&)                - вставить
//   6. remove(const T&)                - удалить
//   7. find(const T&)                  - найти
//   8. inorder()                       - обход в порядке
//   9. preorder()                      - префиксный обход
//  10. postorder()                     - постфиксный обход
//  11. size()                          - размер
//  12. height()                        - высота
//  13. clear()                         - очистить
//  14. is_empty()                      - пусто ли

// void test_remove() { ... }
// void test_find() { ... }

int main() {
    std::cout << "Running BinarySearchTree tests" << std::endl;
    default_constructor_test();
    copy_constructor_test();
    assignement_operator_test();
    insert_test();
    remove_test();
    find_test();
    inorder_test();
    preorder_test();
    postorder_test();
    size_test();
    height_test();
    clear_test();
    is_empty_test();
    std::cout << "All tests passed" << std::endl;
    return 0;
}
