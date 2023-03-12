#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>

using namespace std;

// print contents of STL container
template<typename T>
void PrintStl(T x) {
    for (auto i = x.begin(); i != x.end(); i++) {
        std::cout << *i << "    ";
    }
    std::cout << std::endl;
}

// print basic variable
template<typename T>
void PrintNor(T x) {
    std::cout << x << std::endl;
}

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void PrintList(ListNode *head) {
    ListNode *p = head;
    while (p != nullptr) {
        cout << p->val << "    ";
        p = p->next;
    }
    cout << endl;
}

// create list with data value in vector, and return the address of head node
ListNode *CreateList(vector<int> data) {
    vector<ListNode *> mem_addr = {};
    for (auto i = data.begin(); i != data.end(); i++) {
        mem_addr.push_back(new ListNode(*i));
    }

    for (auto i = mem_addr.begin(); i != mem_addr.end(); i++) {
        (*i)->next = *(i + 1);
    }
    (*(mem_addr.end()-1))->next= nullptr;
    return mem_addr[0];


}

int main() {
    vector<int> data = {1,2,6,3,4,5,6};
    int val =6;
    ListNode* head = CreateList(data);
    PrintList(head);

    ListNode* p = head;
    while(p!= nullptr){
        if(p->val==val){
            if(p->next= nullptr)
            p->next=p->next->next;
        }
        if(p->next== nullptr){
            break;
        }
        p=p->next;
    }
    PrintList(head);

}
