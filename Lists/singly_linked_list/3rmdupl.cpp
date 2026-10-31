#include <iostream>
#include <cassert>

struct Node{
    int data;
    Node* next;
    Node(const int& data):data(data), next(nullptr){}
};

void rmdupl(Node* head){
    Node* curr = head;
    
    while(curr != nullptr && curr->next != nullptr){
        if(curr->data == curr->next->data){
            Node* dupl = curr->next;
            curr->next = dupl->next; 
            delete dupl;
        }
        curr = curr->next;
    }
}

void test(){
    Node* a = new Node(1);
    a->next = new Node(1);
    a ->next->next = new Node(37);
    a->next->next->next = new Node(37);
    a->next->next->next->next = new Node(67);
    rmdupl(a);
    assert(a->data == 1);
    assert(a->next->data == 37);
    assert(a->next->next->data == 67);

    std::cout << "All tests passed\n";
}

int main(){
    std::cout << "Running rmdupl tests... ";
    test();
    return 0;
}