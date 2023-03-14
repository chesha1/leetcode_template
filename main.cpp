#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <map>
#include "utils.h"

using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode *head) {
    ListNode *p = head;
    while (p != nullptr) {
        cout << p->val << "    ";
        p = p->next;
    }
    cout << endl;
}

// create list with data value in vector, and return the address of head node
ListNode *createList(vector<int> data) {
    vector<ListNode *> mem_addr = {};
    for (auto i = data.begin(); i != data.end(); i++) {
        mem_addr.push_back(new ListNode(*i));
    }

    for (auto i = mem_addr.begin(); i != mem_addr.end(); i++) {
        (*i)->next = *(i + 1);
    }
    (*(mem_addr.end() - 1))->next = nullptr;
    return mem_addr[0];


}




int main() {




}
