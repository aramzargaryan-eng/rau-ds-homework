#include <iostream>
#include <stack>
#include <string>
#include <cassert>
#include <cstdint>


bool isBalanced(const std::string& str){
    std::stack<char> c;
    for(uint32_t i = 0; i < str.size(); ++i){
        char curr = str[i];
        if(curr == '(' || curr == '{' || curr == '['){
            c.push(curr);
        }
        else if(curr == ')' || curr == '}' || curr == ']'){
            if(c.empty()){
                return false;
            }
            char top = c.top();
            if((curr == '(' && top != ')') ||
               (curr == '{' && top != '}') ||
               (curr == '[' && top != '}')){
                
                return false;
            }
            c.pop();
        }
    }
    return c.empty();
}

void test(){
    std::string s1 = "({[]})";
    assert(isBalanced(s1));
    std::string s2 = "((({{}}))))";
    assert(!isBalanced(s2));
    std::string s3 = "(((((";
    assert(!isBalanced(s3));
    std::string s4 = "}}}}}}";
    assert(!isBalanced(s4));
    std::string s5;

    std::cout << "testi vrode proxodyat\n";
}

int main(){
    test();
}