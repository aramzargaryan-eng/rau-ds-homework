#include <iostream>
#include <cassert>

struct ListNode{
    int data;
    ListNode* prev;
    ListNode* next;
    ListNode(int data) : data(data), prev(nullptr), next(nullptr){}
};

void erase(ListNode* node){
    if(node == nullptr){
        return;
    }
    
    if(node->prev != nullptr){
        node->prev->next = node->next;
    }

    if(node->next != nullptr){
        node->next->prev = node->prev;
    }

    delete node;
}

void test(){
    ListNode* a = new ListNode(10);
    ListNode* b = new ListNode(20);
    ListNode* c = new ListNode(30);

    a->next = b;
    b->prev = a;
    b->next = c;
    c->prev = b;

    erase(b);

    assert(a->next == c);
    assert(c->prev == a);

    erase(c);
    assert(a->next == nullptr);

    erase(a);

    std::cout << "All tests passed\n";
}

int main(){
    std::cout << "Running some tests... ";
    test();

    return 0;
}