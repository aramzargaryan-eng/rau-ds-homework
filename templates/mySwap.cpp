#include <iostream>
#include <string>

template<typename T>
void mySwap(T& a, T& b){
    T tmp = a;
    a = b;
    b = tmp;
}

void testForInt(){
    int a = 6, b = - 7;
    std::cout << "Before swap: a = " << a << ", b = " << b << '\n';
    mySwap<int>(a, b);
    std::cout << "After swap: a = " << a << ", b = " << b << '\n';
}

void testForDouble(){
    double a = 6.7, b = - 7.11;
    std::cout << "Before swap: a = " << a << ", b = " << b << '\n';
    mySwap<double>(a, b);
    std::cout << "After swap: a = " << a << ", b = " << b << '\n';
}

void testForString(){
    std::string a = "Baylus dzez", b = "вечер в хату";
    std::cout << "Before swap: a = " << a << ", b = " << b << '\n';
    mySwap<std::string>(a, b);
    std::cout << "After swap: a = " << a << ", b = " << b << '\n';
}

int main(){
    testForInt();
    testForDouble();
    testForString();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}