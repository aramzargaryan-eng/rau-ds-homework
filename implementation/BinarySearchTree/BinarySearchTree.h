#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <iostream>
#include <cassert>

template <typename T>
class BinarySearchTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;
        Node(const T& d) : data(d), left(nullptr), right(nullptr) {}
    };
    
    Node* _root;
    int _size;
    
    Node* insert_recursive(Node* node, const T& value);
    Node* remove_recursive(Node* node, const T& value);
    Node* find_recursive(Node* node, const T& value) const;
    void clear_recursive(Node* node);
    int height_recursive(Node* node) const;

    Node* copy_recursive(Node* node);
    void preorder_recursive(Node* node) const;
    void inorder_recursive(Node* node) const;
    void postorder_recursive(Node* node) const;

public:
    /// 1. Конструктор по умолчанию
    BinarySearchTree();
    
    /// 2. Деструктор
    ~BinarySearchTree();
    
    /// 3. Конструктор копирования
    BinarySearchTree(const BinarySearchTree& other);
    
    /// 4. Оператор присваивания
    BinarySearchTree& operator=(const BinarySearchTree& other);
    
    /// 5. insert(const T& value) - вставить
    void insert(const T& value);
    
    /// 6. remove(const T& value) - удалить
    void remove(const T& value);
    
    /// 7. find(const T& value) - найти элемент
    bool find(const T& value) const;
    
    /// 8. inorder() - обход в порядке (выводит на консоль)
    void inorder() const;
    
    /// 9. preorder() - префиксный обход
    void preorder() const;
    
    /// 10. postorder() - постфиксный обход
    void postorder() const;
    
    /// 11. size() - количество элементов
    int size() const;
    
    /// 12. height() - высота дерева
    int height() const;
    
    /// 13. clear() - очистить
    void clear();
    
    /// 14. is_empty() - пусто ли
    bool is_empty() const;
};

// вспомогательные функции
template <typename T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::insert_recursive(Node* node, const T& value){
    if(node == nullptr){
        ++_size;
        return new Node(value);
    }
    if(value < node->data){
        node->left = insert_recursive(node->left, value);
    }
    else if(node->data < value){
        node->right = insert_recursive(node->right, value);
    }
    return node;
}

template <typename T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::remove_recursive(Node* node, const T& value){
    if(node == nullptr){
        return nullptr;
    }
    if(value < node->data){
        node->left = remove_recursive(node->left, value);
    }
    else if(node->data < value){
        node->right = remove_recursive(node->right, value);
    }
    else{
        if(node->left == nullptr){
            Node* right = node->right;
            delete node;
            --_size;
            return right;
        }
        if(node->right == nullptr){
            Node* left = node->left;
            delete node;
            --_size;
            return left;
        }

        Node* child = node->right;
        while(child->left){
            child = child->left;
        }
        node->data = child->data;
        node->right = remove_recursive(node->right, child->data);
    }
    return node;
}

template <typename T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::find_recursive(Node* node, const T& value) const{
    if(node == nullptr){
        return nullptr;
    }
    if(value < node->data){
        return find_recursive(node->left, value);
    }
    if(node->data < value){
        return find_recursive(node->right, value);
    }
    return node;
}

template <typename T>
void BinarySearchTree<T>::clear_recursive(Node* node){
    if(node == nullptr){
        return;
    }
    clear_recursive(node->left);
    clear_recursive(node->right);
    delete node;
}

template <typename T>
int BinarySearchTree<T>::height_recursive(Node* node) const{
    if(node == nullptr){
        return 0;
    }
    int left_h = height_recursive(node->left);
    int right_h = height_recursive(node->right);

    if(left_h < right_h){
        return 1 + right_h;
    }
    else{
        return 1 + left_h;
    }
}

template <typename T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::copy_recursive(Node* node){
    if(node == nullptr){
        return nullptr;
    }
    Node* new_node = new Node(node->data);
    new_node->left = copy_recursive(node->left);
    new_node->right = copy_recursive(node->right);
    return new_node;
}

template <typename T>
void BinarySearchTree<T>::preorder_recursive(Node* node) const{
    if(node == nullptr){
        return;
    }
    std::cout << node->data << " ";
    preorder_recursive(node->left);
    preorder_recursive(node->right);
}

template <typename T>
void BinarySearchTree<T>::inorder_recursive(Node* node) const{
    if(node == nullptr){
        return;
    }
    inorder_recursive(node->left);
    std::cout << node->data << " ";
    inorder_recursive(node->right);
}

template <typename T>
void BinarySearchTree<T>::postorder_recursive(Node* node) const{
    if(node== nullptr){
        return;
    }
    postorder_recursive(node->left);
    postorder_recursive(node->right);
    std::cout << node->data << " ";
}

// публичные методы

//1. дефолтный конструктор
template <typename T>
BinarySearchTree<T>::BinarySearchTree(): _root(nullptr), _size(0){}

//2.деструктор
template <typename T>
BinarySearchTree<T>::~BinarySearchTree(){
    clear();
}

//3.конструктор копирования
template <typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree& other): _root(nullptr), _size(0){
    _root = copy_recursive(other._root);
    _size = other._size;
}

//4. оператор присваивания
template <typename T>
BinarySearchTree<T>& BinarySearchTree<T>::operator=(const BinarySearchTree& other){
    if(this != &other){
        clear();
        _root = copy_recursive(other._root);
        _size = other._size;
    }
    return *this;
}

//5. insert
template <typename T>
void BinarySearchTree<T>::insert(const T& value){
    _root = insert_recursive(_root, value);
}

//6. remove
template <typename T>
void BinarySearchTree<T>::remove(const T& value){
    _root = remove_recursive(_root, value);
}

//7. find
template <typename T>
bool BinarySearchTree<T>::find(const T& value) const{
    return find_recursive(_root, value) != nullptr;
}

//8. inorder
template <typename T>
void BinarySearchTree<T>::inorder() const{
    inorder_recursive(_root);
    std::cout << '\n';
}

//9. preorder
template <typename T>
void BinarySearchTree<T>::preorder() const{
    preorder_recursive(_root);
    std::cout << '\n';
}

//10. postorder
template <typename T>
void BinarySearchTree<T>::postorder() const{
    postorder_recursive(_root);
    std::cout << '\n';
}

//11. size
template <typename T>
int BinarySearchTree<T>::size() const{
    return _size;
}

//12. height
template <typename T>
int BinarySearchTree<T>::height() const{
    return height_recursive(_root);
}

//13 clear
template <typename T>
void BinarySearchTree<T>::clear(){
    clear_recursive(_root);
    _root = nullptr;
    _size = 0;
}

//14. is_empty
template <typename T>
bool BinarySearchTree<T>::is_empty() const{
    return _root == nullptr;
}

#endif // BINARYSEARCHTREE_H
