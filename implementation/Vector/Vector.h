#pragma once
#include <stdexcept>
#include <cstddef>
#include <string>

template <typename T>
class Vector{
    private:
        T* data;
        int _size;
        int capacity;

    public:
        Vector();
        ~Vector();
        Vector(const Vector& other);
        Vector& operator=(const Vector& other);
        int size() const;
        int cap() const;
        bool empty() const;
        void push_back(const T& x);
        void pop_back();
        T& operator[](int index);
        T& back();
        void insert(int pos, const T& val);
        void erase(int pos);
        void swap(Vector& other);
        void clear();
        void resize(int new_size);
        T& front();
};
//1)default constructor
template <typename T>
Vector<T>::Vector() : data(nullptr), _size(0), capacity(0) {}

//2)destructor
template <typename T>
Vector<T>::~Vector(){
    delete[] data;
}

//3)copy constructor
template <typename T>
Vector<T>::Vector(const Vector& other) : data(nullptr), _size(0), capacity(0){
    if(other._size > 0){
        data = new T[other.capacity];
        capacity = other.capacity;
        for(int i = 0; i < other._size; ++i){
            data[i] = other.data[i];
        }
        _size = other._size;
    }
}

//4)operator=
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& other){
    if(this == &other){
        return *this;
    }

    T* new_data = nullptr;
    if(other._size > 0){
        new_data = new T[other.capacity];
        for(int i = 0; i < other._size; ++i){
            new_data[i] = other.data[i];
        }
    }
    delete[] data;
    data = new_data;
    _size = other._size;

    if(other._size > 0){
        capacity = other.capacity;
    }
    else{
        capacity = 0;
    }
    return *this;
}

// est v teste main.cpp, poetomu sdelal
template <typename T>
int Vector<T>::size()const{
    return _size;
}

// dlya testa xochu capacity
template <typename T>
int Vector<T>::cap()const{
    return capacity;
}

// tozhe vspomogatelni metod, udobnosti radi
template <typename T>
bool Vector<T>::empty()const{
    return _size == 0;
}

//5) push_back
template <typename T>
void Vector<T>::push_back(const T& x){
    T tmp = x;

    if(_size == capacity){
        int new_cap;
        if(capacity == 0){
            new_cap = 2;
        }
        else if(capacity == 1){
            new_cap = (capacity * 2);
        }
        else{
            new_cap = (capacity * 1.5);
        }
        T* new_data = new T[new_cap];

        for(int i = 0; i < _size; ++i){
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity = new_cap;
    }
    data[_size] = tmp;
    ++_size;
}

//6) pop_back
template <typename T>
void Vector<T>::pop_back(){
    if(_size == 0){
        throw std::out_of_range("ara Vector pust");
    }
    --_size;
}

//7)operator[]
template <typename T>
T& Vector<T>::operator[](int index){
    return data[index];
}

//8)back()
template <typename T>
T& Vector<T>::back(){
    if(_size == 0){
        throw std::out_of_range("ara Vector pust");
    }
    return data[_size - 1];
}

//9)insert()
template <typename T>
void Vector<T>::insert(int pos, const T& val){
    if(pos < 0 || pos > _size){
        throw std::out_of_range("znay svoi granici");
    }
    T tmp = val;
    if(_size == capacity){
        int new_cap;
        if(capacity == 0){
            new_cap = 1;
        }
        else if(capacity == 1){
            new_cap = (capacity * 2);
        }
        else{
            new_cap = (capacity * 1.5);
        }

        T* new_data = new T[new_cap];
        for(int i = 0; i < pos; ++i){
            new_data[i] = data[i];
        }
        new_data[pos] = tmp;
        for(int i = _size; i > pos; --i){
            new_data[i] = data[i - 1];
        }
        delete[] data;
        data = new_data;
        capacity = new_cap;

    }
    else{

        for(int i = _size; i > pos; --i){
            data[i] = data[i - 1];
        }
        data[pos] = tmp;
    }
    ++_size;
}

//10)erase()
template <typename T>
void Vector<T>::erase(int pos){
    if(pos < 0 || pos >= _size){
        throw std::out_of_range("znay svoi granici");
    }
    for(int i = pos; i < _size - 1; ++i){
        data[i] = data[i+1];
    }
    --_size;
}

//11)swap()
template <typename T>
void Vector<T>::swap(Vector& other){
    T* tmp_data = data;
    data = other.data;
    other.data = tmp_data;

    int tmp_size = _size;
    _size = other._size;
    other._size = tmp_size;

    int tmp_cap = capacity;
    capacity = other.capacity;
    other.capacity = tmp_cap;
}

//12)clear()
template <typename T>
void Vector<T>::clear(){
    _size = 0;
}

//13)resize()
template <typename T>
void Vector<T>::resize(int new_size){
    if(new_size < 0){
        throw std::out_of_range("ara kakoy otricatelni size");
    }

    if(new_size > capacity){
        T* new_data = new T[new_size];

        for(int i = 0; i < _size; ++i){
        new_data[i] = data[i];
        }
    
        delete[] data;
        data = new_data;
        capacity = new_size;
    }

    for(int i = _size; i < new_size; ++i){
        data[i] = T();
    }
    _size = new_size;    
}

//14) front()
template <typename T>
T& Vector<T>::front(){
    if(_size == 0){
        throw std::out_of_range("ara Vector pust");
    }
    return *data;
} 
