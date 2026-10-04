#include <iostream>
#include <vector>
#include <cassert>
#include <cstddef>

bool isEven(int n){
    return n % 2 == 0;
}

bool isOdd(int n){
    return n % 2 != 0;
}

bool isPrime(int n){
    if(n <= 1){
        return false;
    }
    for(int i = 2; i * i <= n; ++i){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

bool isPositive(int n){
    return n > 0;
}

template<typename T, typename Predicate>
std::vector<T> filterVector(const std::vector<T>& vec, Predicate pred){
    std::vector<T> result;
    for(std::size_t i = 0; i < vec.size(); ++i){
        if(pred(vec[i])){
            result.push_back(vec[i]);
        }
    }
    return result;
}

void print(const std::vector<int>& vec){
    for(std::size_t i = 0; i < vec.size(); ++i){
        std::cout << vec[i] << " ";
    }
    std::cout << '\n';
}

void test(){
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> evenNumbers = filterVector(vec, isEven);
    assert(evenNumbers == std::vector<int>({2, 4, 6, 8, 10}));
    std::vector<int> oddNumbers = filterVector(vec, isOdd);
    assert(oddNumbers == std::vector<int>({1, 3, 5, 7, 9}));
    std::vector<int> primeNumbers = filterVector(vec, isPrime);
    assert(primeNumbers == std::vector<int>({2, 3, 5, 7}));
    std::vector<int> positiveNumbers = filterVector(vec, isPositive);
    assert(positiveNumbers == std::vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}));
    std::vector<int> emptyVec = {};
    std::vector<int> filteredEmptyVec = filterVector(emptyVec, isEven);
    assert(filteredEmptyVec.empty());
    std::cout << "All tests passed!" << '\n';
}

int main(){
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> evenNumbers = filterVector(vec, isEven);
    std::cout << "Even numbers: ";
    print(evenNumbers);
    std::vector<int> oddNumbers = filterVector(vec, isOdd);
    std::cout << "Odd numbers: ";
    print(oddNumbers);
    std::vector<int> primeNumbers = filterVector(vec, isPrime);
    std::cout << "Prime numbers: ";
    print(primeNumbers);
    std::vector<int> positiveNumbers = filterVector(vec, isPositive);
    std::cout << "Positive numbers: ";
    print(positiveNumbers);
    test();
    return 0;
}