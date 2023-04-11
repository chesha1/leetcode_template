//
// Created by chesh on 2023/4/10.
//
#include "struc.h"
#include <vector>
#include <iostream>

// create list with data value in std::vector, and return the address of head node
ListNode *createList(std::vector<int> data) {
    std::vector<ListNode *> mem_addr = {};
    for (auto i = data.begin(); i != data.end(); i++) {
        mem_addr.push_back(new ListNode(*i));
    }

    for (auto i = mem_addr.begin(); i != mem_addr.end(); i++) {
        (*i)->next = *(i + 1);
    }
    (*(mem_addr.end() - 1))->next = nullptr;
    return mem_addr[0];
}

void printList(ListNode *head) {
    ListNode *p = head;
    while (p != nullptr) {
        std::cout << p->val << "    ";
        p = p->next;
    }
    std::cout << std::endl;
}

TreeNode *createTree(std::vector<std::vector<int> > data) {
    std::vector<TreeNode *> mem_addr = {};
    for (auto i = data.begin(); i != data.end(); i++) {
        auto temp = *i;
        for (auto j = temp.begin(); j != temp.end(); j++) {
            mem_addr.push_back(new TreeNode(*j));
        }
    }

    int length = mem_addr.size();
    for (auto i = 0; i < length; i++) {
        if (2 * i < length - 1) {
            mem_addr[i]->left = mem_addr[2 * i + 1];
            mem_addr[i]->right = mem_addr[2 * i + 2];
            if (mem_addr[2 * i + 1]->val == -1) mem_addr[i]->left = nullptr;
            if (mem_addr[2 * i + 2]->val == -1) mem_addr[i]->right = nullptr;
        } else {
            mem_addr[i]->left = nullptr;
            mem_addr[i]->right = nullptr;
        }

    }
    return mem_addr[0];
}