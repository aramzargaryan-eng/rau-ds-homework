#include <iostream>
#include <cassert>
#include <string>
#include <cmath>

template <typename T>
class Range {
private:
    T start;
    T end;
public:
    Range(T s, T e) : start(s), end(e) {}
    bool contains(const T& value) const;
    T length() const;
    void print() const;
};

template <typename T>
bool Range<T>::contains(const T& value) const{
    if(value >= start && value <= end){
        return true;
    }
    return false;
}

template <typename T>
T Range<T>::length() const{
    return end - start;
}

template <typename T>
void Range<T>::print() const{
    std::cout << "[" << start << ", " << end<< "]" << '\n';
}

void RangeTest(){
    Range<int> r1(3, 10);
    assert(r1.contains(5) == true);
    assert(r1.contains(15) == false);
    assert(r1.length() == 7);
    std::cout << "Range for int is: ";
    r1.print();
    std::cout << '\n';


    Range<double> r2(0.5, 5.5);
    assert(r2.contains(3.0) == true);
    assert(r2.contains(6.0) == false);
    assert(std::abs(r2.length()) - 5.0 < 1e-9);
    std::cout << "Range for double is: ";
    r2.print();
    std::cout << '\n';


    Range<char> r3('a', 'f');
    assert(r3.contains('b') == true);
    assert(r3.contains('o') == false);
    assert(r3.length() == 5);
    std::cout << "Range for char is: ";
    r3.print();
    std::cout << '\n';

    std::cout << "All tests passed!" << '\n';
}

int main(){
    RangeTest();
    return 0;
}
   