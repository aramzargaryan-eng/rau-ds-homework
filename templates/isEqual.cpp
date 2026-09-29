#include <iostream>
#include <cstring>
#include <cassert>

template <typename T>
bool isEqual(const T& a, const T& b){
    return a == b;
}

template<>
bool isEqual<const char*>(const char* const& a, const char* const & b){
    return std::strcmp(a, b) == 0;
}

int main(){
    std::cout << isEqual<int>(5, 5) << '\n';
    std::cout << isEqual<double>(3.14, 2.71) << '\n';

    const char* str1 = "six";
    const char* str2 = "six";
    const char* str3 = "seven";

    std::cout << isEqual<const char*>(str1, str2) << '\n';
    std::cout << isEqual<const char*>(str1, str3) << '\n';

    assert(isEqual<const char*>(str1, str2));
    assert(!isEqual<const char*>(str1, str3));

    std::cout << "All tests passed" << '\n';
    return 0;
}