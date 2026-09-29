#include <iostream>
#include <cassert>
#include <string>

template <typename T>
void PrintValue(const T& value){
    std::cout << "Value: " << value << '\n';
}
template <>
void PrintValue<bool>(const bool& value){
    std::cout << "Value: " << (value ? "true" : "false") << '\n';
}
template <>
void PrintValue<char*>(char* const& value){
    std::cout << "Value: " <<'"' << value << '"' << '\n';
}

void PrintTest(){
    PrintValue<int>(67);
    PrintValue<double>(6.7);
    PrintValue<bool>(true);
    PrintValue<bool>(false);

    char text[] = "sixseven";
    PrintValue<char*>(text);
}

int main(){
    PrintTest();
    std::cout << "print tests passed" << '\n';
    return 0;
}