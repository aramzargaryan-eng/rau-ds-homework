#include <iostream>
#include <queue>
#include <cassert>
#include <vector>
#include <utility>
#include <stdexcept>

// как я понял, в реализции STL-овских контейнеров для всяких 
// индексов и методов, возвращяющих положительное значение, использовали 
// тип std::size_t. И по хорошему, не совсем корректно сравнивать
// int и std::size_t(а в коде такие сравнения есть).
// можно, конечно использовать static_cast<int>(tickets.size()),
// например, чтобы превратить tickets.size() в int, 
// но код и так работал, а static_cast мозолит глаза

int timeRequiredToBuy(const std::vector<int>& tickets, int K){
    if(K < 0 || K >= tickets.size()){
        throw std::out_of_range("hn...");
    }

    if(tickets[K] <= 0){
        return 0;
    }
   
    std::queue<std::pair<int, int>> q;
    for(int i = 0; i < tickets.size(); ++i){
        if(tickets[i] > 0){
            q.push(std::pair<int, int>(i, tickets[i]));
        }    
    }
    int time = 0;
    while(q.size() > 0){
        std::pair<int, int> tmp = q.front();
        int index = tmp.first;
        int ticket = tmp.second;

        q.pop();
        ++time;
        --ticket;

        if(ticket == 0){
            if (index == K){
                return time;
            }
        }
        else{
            q.push(std::pair<int, int>(index, ticket));
        }
    }
    return time;
}

void test(){
    std::vector<int> tickets1 = {3, 4, 2, 1};
    bool thrown = false;
    try{
    timeRequiredToBuy(tickets1, 4);
    }
    catch(const std::out_of_range&){
        thrown = true;
    }
    assert(thrown);

    std::vector<int> tickets2 = {3, 4, 2, 1};
    thrown = false;
    try{
    timeRequiredToBuy(tickets2, -9);
    }
    catch(const std::out_of_range&){
        thrown = true;
    }
    assert(thrown);

    std::vector<int> tickets3;
    thrown = false;
    try{
    timeRequiredToBuy(tickets3, 0);
    }
    catch(const std::out_of_range&){
        thrown = true;
    }
    assert(thrown);
    
    std::cout << "passed\n";
}

int main(){
    std::cout << "github example test: ";
    std::vector<int> tickets1 = {2, 3, 2};
    std::cout << timeRequiredToBuy(tickets1, 2) << '\n';

    std::cout << "my test: ";
    test();
    
    return 0;
}