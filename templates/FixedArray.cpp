#include <iostream>
#include <cassert>
#include <string>

template<typename T, int N>
class FixedArray{
private:
    T arr[N];

public:
    void set(int index, const T& value);
    T get(int index) const;
    int size() const;
};

template <typename T, int N>
void FixedArray<T, N>::set(int index, const T& value){
    if(index >= 0 && index < N){
        arr[index] = value;
    }
    else{
        std::cout << "za predelami massiva:(" << '\n'; 
    }
}

template <typename T, int N>
T FixedArray<T, N>::get(int index) const{
    if(index >= 0 && index < N){
        return arr[index];
    }
    else{
        std::cout << "za predelami massiva:(" << '\n'; 
        return {};
    }
}

template <typename T, int N>
int FixedArray<T, N>::size() const{
    return N;
}

void testForInt(){
    FixedArray<int, 3> arr;
    arr.set(0, 6);
    arr.set(1, 7);
    arr.set(2, -67);

    assert(arr.get(0) == 6);
    assert(arr.get(1) == 7);
    assert(arr.get(2) == -67);
    assert(arr.size() == 3);

    std::cout << "int tests passed" <<  '\n';
}

void testForDouble(){
    FixedArray<double, 3> arr;
    arr.set(0, 6.7);
    arr.set(1, -7.6);
    arr.set(2, -6.767);

    assert(arr.get(0) == 6.7);
    assert(arr.get(1) == -7.6);
    assert(arr.get(2) == -6.767);
    assert(arr.size() == 3);

    std::cout << "double tests passed" <<  '\n';
}

void testForString(){
    FixedArray<std::string, 3> arr;
    arr.set(0, "baylus");
    arr.set(1, "dzez");
    arr.set(2, "вечер в хату");

    assert(arr.get(0) == "baylus");
    assert(arr.get(1) == "dzez");
    assert(arr.get(2) == "вечер в хату");
    assert(arr.size() == 3);

    std::cout << "string tests passed" <<  '\n';
}

void testForChar(){
    FixedArray<char, 3> arr;
    arr.set(0, 'a');
    arr.set(1, 'b');
    arr.set(2, 'n');

    assert(arr.get(0) == 'a');
    assert(arr.get(1) == 'b');
    assert(arr.get(2) == 'n');
    assert(arr.size() == 3);

    std::cout << "char tests passed" <<  '\n';
}

void invalidIndexTest(){
    FixedArray<int, 2> arr;
    arr.set(0, 67);
    arr.set(1, -67);

    arr.set(2, 6776); // za predelami massiva:(
    arr.set(-1, 435); // za predelami massiva:(

    arr.get(2);       // za predelami massiva:(
    arr.get(-1);      // za predelami massiva:(

    std::cout << "za predeli ne vixodit:)" << '\n';
}

int main(){
    testForInt();
    testForDouble();
    testForString();
    testForChar();
    invalidIndexTest();

    std::cout << "All tests passed" << '\n';
    return 0;
}

