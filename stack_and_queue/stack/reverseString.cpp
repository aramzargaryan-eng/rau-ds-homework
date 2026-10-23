#include <iostream>
#include <cassert>
#include <cstddef>
#include <stack>

void reverseString(std::string& str){
    std::stack<char> st;
    for(char c : str){
        st.push(c);
    }
    for(std::size_t i = 0; i < str.size(); ++i){
        str[i] = st.top();
        st.pop();
    }
}

void test(){
    std::string s1 = "hopar";
    reverseString(s1);
    assert(s1 == "rapoh");

    std::string s2 = "racecar";
    reverseString(s2);
    assert(s2 == "racecar");                 // палиндром)

    std::string s3 = "palindrom";
    reverseString(s3);
    assert(s3 == "mordnilap");               // не палиндром(
    
    std::string s4;
    reverseString(s4);
    assert(s4 == "");
    
    std::cout << "All tests passed\n";
}

int main(){
    std::cout << "github example test: ";

    std::string s = "Hello";
    reverseString(s);
    std::cout << s << '\n';

    std::cout << "Running my tests: ";
    test();
    
    return 0;
}