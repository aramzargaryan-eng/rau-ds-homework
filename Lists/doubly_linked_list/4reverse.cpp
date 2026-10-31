#include <iostream>
#include <cassert>

struct ListNode{
    int data;
    ListNode* prev;
    ListNode* next;
    ListNode(int data):data(data), prev(nullptr), next(nullptr){}
};

ListNode* reverse(ListNode* head){
    ListNode* curr = head;
    while(curr){
        ListNode* tmp = curr->next;
        curr->next = curr->prev;
        curr->prev = tmp;

        head = curr;
        curr = tmp;
    }
    return head;
}

void test(){
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(3);
    ListNode* d = new ListNode(4);
    ListNode* e = new ListNode(5);
    ListNode* f = new ListNode(6);
    ListNode* g = new ListNode(7);

    a->next = b;
    b->prev = a;
    b->next = c;
    c->prev = b;
    c->next = d;
    d->prev = c;
    d->next = e;
    e->prev = d;
    e->next = f;
    f->prev = e;
    f->next = g;
    g->prev = f;

    std::cout << "List before reverse: ";
    for(ListNode* curr = a; curr != nullptr; curr = curr->next){
        std::cout << curr->data << " ";
    }
    std::cout << '\n';

    a = reverse(a);

    std::cout << "List after reverse:  ";
    for(ListNode* curr = a; curr != nullptr; curr = curr->next){
        std::cout << curr->data << " ";
    }
    std::cout << '\n';

    assert(a->data == 7);
    assert(a->prev == nullptr);
    assert(a->next->data == 6);
    assert(a->next->prev == a);

    ListNode* curr = a;
    while(curr){
        ListNode* _next = curr->next;
        delete curr;
        curr = _next;
    }
    
    std::cout << "All tests passed\n";
}

int main(){
    std::cout << "Running some tests\n"; 
    test();
    return 0;
}