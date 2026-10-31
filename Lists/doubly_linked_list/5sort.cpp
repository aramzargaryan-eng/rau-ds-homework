#include <iostream>
#include <cassert>

struct ListNode{
    int data;
    ListNode* prev;
    ListNode* next;
    ListNode (int data) : data(data), prev(nullptr), next(nullptr){}
};

void sort(ListNode* head){
    if (head == nullptr || head->next == nullptr){
        return;
    }

    ListNode* end = nullptr;
    bool flag = true;

    while(flag){
        flag = false;
        ListNode* curr = head;

        while(curr->next != end){
            if(curr->data > curr->next->data){
                int tmp = curr->data;
                curr->data = curr->next->data;
                curr->next->data = tmp;
                flag = true;
            }
            curr = curr->next;
        }
        end = curr;
    }
}

void test(){
    ListNode* a = new ListNode(10);
    ListNode* b = new ListNode(54);
    ListNode* c = new ListNode(23);
    ListNode* d = new ListNode(4);
    ListNode* e = new ListNode(1);
    ListNode* f = new ListNode(5);

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

    std::cout << "List before sort: ";
    for(ListNode* curr = a; curr != nullptr; curr = curr->next){
        std::cout << curr->data << " ";
    }
    std::cout << '\n';

    sort(a);

    std::cout << "List after sort:  ";
    for(ListNode* curr = a;curr != nullptr; curr = curr->next){
        std::cout << curr->data << " ";
    }
    std::cout << '\n';

    for(ListNode* curr = a; curr->next != nullptr; curr = curr->next){
        assert(curr->data <= curr->next->data);
    }

    ListNode* curr = a;
    while(curr != nullptr){
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