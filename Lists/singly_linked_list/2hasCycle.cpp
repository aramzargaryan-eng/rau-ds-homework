#include <iostream>
#include <cassert>

struct Node{
    int data;
    Node* next;
    Node(const int data):data(data), next(nullptr){}
};

bool hasCycle(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            return true;
        }
    }
    return false;
}

void test(){
    assert(!hasCycle(nullptr));

    Node a = 10;
    assert(!hasCycle(&a));

    Node b = 20;
    a.next = &b;
    assert(!hasCycle(&a));

    Node c = 30;
    b.next = &c;
    assert(!hasCycle(&a));
    
    Node d = 40;
    c.next = &d;
    d.next = &b;
    assert(hasCycle(&a));

    std::cout << "All tests passed\n";
}

int main(){
    std::cout << "Running hasCycle tests... ";
    test();
}