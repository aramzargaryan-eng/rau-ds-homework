#ifndef FORWARDLIST_H
#define FORWARDLIST_H
#include <stdexcept>

template <typename T>
class ForwardList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& d) : data(d), next(nullptr) {}
    };
    
    Node* _head;
    int _size;

public:
    /// 1. Конструктор по умолчанию
    ForwardList();
    
    /// 2. Деструктор
    ~ForwardList();
    
    /// 3. Конструктор копирования
    ForwardList(const ForwardList& other);
    
    /// 4. Оператор присваивания
    ForwardList& operator=(const ForwardList& other);
    
    /// 5. push_front(const T& x) - добавить в начало
    void push_front(const T& x);
    
    /// 6. pop_front() - удалить с начала
    void pop_front();
    
    /// 7. front() - первый элемент
    T& front();
    const T& front() const;
    
    /// 8. insert_after(Node* node, const T& value) - вставить после узла
    void insert_after(Node* node, const T& value);
    
    /// 9. erase_after(Node* node) - удалить после узла
    void erase_after(Node* node);
    
    /// 10. clear() - очистить
    void clear();
    
    /// 11. reverse() - развернуть
    void reverse();
    
    /// 12. size() - количество элементов
    int size() const;
    
    /// 13. empty() - пуст ли
    bool empty() const;
    
    /// 14. begin() - начало списка
    Node* begin();
    Node* begin() const;
};

//1)default constructor
template <typename T>
ForwardList<T>::ForwardList() : _head(nullptr), _size(0){}

//2) destructor
template <typename T>
ForwardList<T>::~ForwardList(){
    clear();
}

//3) copy constructor
template <typename T>
ForwardList<T>::ForwardList(const ForwardList& other) : _head(nullptr), _size(0){
    Node* tail = nullptr;
    for(Node* cur = other._head; cur; cur = cur->next){
        Node* n = new Node(cur->data);
        if(tail){
            tail->next = n;
        }
        else{
            _head = n;
        }
        tail = n;
        ++_size;
    }
}

//4)operator=
template <typename T>
ForwardList<T>& ForwardList<T>::operator=(const ForwardList& other){
    if(this != &other){
        clear();

        Node* tail = nullptr;
        for(Node* cur = other._head; cur; cur = cur->next){
            Node* n = new Node(cur->data);
            if(tail){
                tail->next = n;
            }
            else{
                _head = n;
            }
            tail = n;
            ++_size;
        }
    }
    return* this;
}

//5) push_front
template <typename T>
void ForwardList<T>::push_front(const T& x){
    Node* newnode = new Node(x);
    newnode-> next = _head;
    _head = newnode;
    ++_size;
}

//6)pop_front
template <typename T>
void ForwardList<T>::pop_front(){
    if(_size == 0){
        throw std::out_of_range("а чо ты удаляешь...");
    }
    Node* tmp = _head;
    _head = _head->next;
    delete tmp;
    --_size;
}

//7) front
template <typename T>
T& ForwardList<T>::front(){
    if(_size == 0){
        throw std::out_of_range("че ищешь...");
    }
    return _head->data;
}
template <typename T>
const T& ForwardList<T>::front()const{
    if(_size == 0){
        throw std::out_of_range("че ищешь...");
    }
    return _head->data;
}

//8)insert_after
template <typename T>
void ForwardList<T>::insert_after(Node* node, const T& value){
    if(node == nullptr){
        throw std::invalid_argument("куда смотришь...");
    }
    Node* newnode = new Node(value);
    newnode->next = node->next;
    node->next = newnode;
    ++_size;
}

//9)erase_after
template <typename T>
void ForwardList<T>::erase_after(Node* node){
    if(node == nullptr || node->next == nullptr){
        throw std::invalid_argument("куда смотришь...");
    }
    Node* tmp = node->next;
    node->next = tmp->next;
    delete tmp;
    --_size;
}

//10) clear();
template <typename T>
void ForwardList<T>::clear(){
    while(_head){
        Node* tmp = _head;
        _head = _head->next;
        delete tmp;
    }
    _size = 0;
}

//11)reverse
template <typename T>
void ForwardList<T>::reverse(){
    Node* prev = nullptr;
    Node* curr = _head;
    while(curr){
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    } 
    _head = prev;
}

//12) size
template<typename T>
int ForwardList<T>::size() const{
    return _size;
}

//13)empty
template <typename T>
bool ForwardList<T>::empty() const{
    return _head == nullptr;
}

//14)begin
template <typename T>
typename ForwardList<T>::Node* ForwardList<T>::begin(){
    return _head;
}
template <typename T>
typename ForwardList<T>::Node* ForwardList<T>::begin() const{
    return _head;
}
#endif // FORWARDLIST_H
