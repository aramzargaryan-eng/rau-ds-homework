#include <iostream>
#include <queue>
#include <cassert>
#include <vector>
#include <string>
#include <cstddef>

std::string hotPotato(const std::vector<std::string>& geymers, std::size_t K){
    if(geymers.empty()){
        throw std::invalid_argument("ara igrokov net");
    }

    std::queue<std::string> q;

    for(const auto& geymer : geymers){
        q.push(geymer);
    }
    while(q.size() > 1){
        for(std::size_t i = 0; i < K; ++i){
            q.push(q.front());
            q.pop();
        }
        q.pop();
    }
    return q.front();
}

void test(){
    std::vector<std::string> players;
    bool thrown = false;
    try{
        hotPotato(players, 9);
    }
    catch(const std::invalid_argument&){
        thrown = true;
    }
    assert(thrown);
    
    std::vector<std::string> players2 = {"kadirov", "don don ovechka"};
    assert(hotPotato(players2, 8) == "don don ovechka");

    std::cout << "all tests passed\n";
}

int main(){
    std::cout << "github example test: ";
    std::vector<std::string> players = {"Alice", "Bob", "Charlie", "David"};
    std::cout << hotPotato(players, 7) << '\n'; 

    std::cout << "my tests: ";
    test();

    return 0;
}
