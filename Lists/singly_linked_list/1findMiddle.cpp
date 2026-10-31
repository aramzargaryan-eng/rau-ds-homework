#include <iostream>
#include <cassert>

struct Node{
    int data;
    Node* next;
    Node(const int& data) : data(data), next(nullptr){}
};

Node* findMiddle(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void test(){
    assert(findMiddle(nullptr) == nullptr);
    Node a = 10;
    assert(findMiddle(&a) == &a);

    Node b = 20;
    a.next = &b;
    assert(findMiddle(&a) == &b);

    Node c = 30;
    Node d = 40;
    b.next = &c;
    c.next = &d;

    assert(findMiddle(&a) == &c);

    Node e = 67;
    d.next = &e;

    assert(findMiddle(&a) == &c);

    std::cout << "All tests passed\n";
}

int main(){
    std::cout << "Running findMiddle tests:\n";
    test();
    return 0;
}