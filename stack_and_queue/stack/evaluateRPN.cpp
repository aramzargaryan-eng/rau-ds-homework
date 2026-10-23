#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <cstddef>
#include <stdexcept>
#include <cassert>



double evaluateRPN(const std::vector<std::string>& t){
    std::stack<double> s;
    for(std::size_t i = 0; i < t.size(); ++i){
        const std::string& curr = t[i];

        if(curr == "+" || curr == "-" || curr == "*" || curr == "/"){
            if(s.size() < 2){
                throw std::invalid_argument("brat nu chisel dobav");
            }
            double b = s.top();
            s.pop();
            double a = s.top();
            s.pop();

            if(curr == "+"){
                s.push(a + b);
            }
            else if(curr == "-"){
                s.push(a - b);
            }
            else if(curr == "*"){
                s.push(a * b);
            }
            else if(curr == "/"){
                if(b == 0.0){
                    throw std::invalid_argument("ne deli na nol");
                }
                s.push(a / b);
            }
        }
        else{
            s.push(std::stod(curr));
        }
    }
    if(s.size() != 1){
        throw std::invalid_argument("ara odno znachenie tut doljno bit");
    } 
    return s.top();
}

void test(){
    std::vector<std::string> t1 = {"4", "5", "*", "10", "/"};
    assert(evaluateRPN(t1) == 2);
    
    std::vector<std::string> t2;
    bool thrown = false;
    try{
        evaluateRPN(t2);
    }
    catch(const std::invalid_argument&){
        thrown = true;
    }
    assert(thrown);

    std::vector<std::string> t3 = {"1", "2", "3", "-"};
    thrown = false;
    try{
        evaluateRPN(t3);
    }
    catch(const std::invalid_argument&){
        thrown = true;
    }
    assert(thrown);

    std::cout << "spasi testery ancni sax ara...\n";

    std::vector<std::string> t4 = {"1", "0", "/"};
    thrown = false;
    try{
        evaluateRPN(t4);
    }
    catch(const std::invalid_argument&){
        thrown = true;
    }
    assert(thrown);


    std::cout << "all tests passed\n";
}

int main(){
    std::cout << "github example test: ";

    std::vector<std::string> expr = {"2", "1", "+", "3", "*"};
    std::cout << evaluateRPN(expr) << '\n';
    
    std::cout << "running my tests: ";
    test();

    return 0;
}
