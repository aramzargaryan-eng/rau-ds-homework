#include <iostream>
#include <string>
#include <cassert>

template <typename T>
void printElement(const T& a){
    std::cout << a << '\n';
}

void testForInt(){
    std::cout << "Print for int:" << '\n';
    printElement<int>(6);
    printElement<int>(-7);
}

void testForDouble(){
    std::cout << "Print for double:" << '\n';
    printElement<double>(6.7);
    printElement<double>(-7.11);
}

void testForString(){
    std::cout << "Print for string:" << '\n';
    printElement<std::string>("Baylus dzez");
    printElement<std::string>("вечер в хату");
}

int main(){
    
    testForInt();
    testForDouble();
    testForString();
    
    std::cout << "All tests passed!" << std::endl;

    return 0;
}