#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
#include <string>

std::vector<std::string> generateBinaryNumbers(int N){
    if(N <= 0){
        return{};
    }

    std::vector<std::string> resultat;
    resultat.reserve(N);
    
    std::queue<std::string> q;
    q.push("1");
    
    for(int i = 0; i < N; ++i){
        std::string curr = q.front();
        q.pop();
        resultat.push_back(curr);

        q.push(curr + "0");
        q.push(curr + "1");
    }
    return resultat;
}

void test(){
    auto result = generateBinaryNumbers(-9);
    assert(result.empty());

    auto result1 = generateBinaryNumbers(4);
    assert(result1 == std::vector<std::string>({"1", "10", "11", "100"}));

    std::cout << "my test passed\n";
}

int main(){

    std::cout << "github example test: ";
    auto result = generateBinaryNumbers(5);
    for(const auto& el : result){
        std::cout << el << " ";
    }
    std::cout << '\n';
    std::cout << "running my test: ";
    test();

    return 0;
}