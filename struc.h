//
// Created by chesh on 2023/4/10.
//

#ifndef UNTITLED_STRUC_H
#define UNTITLED_STRUC_H

#include <vector>

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {};

    ListNode(int x) : val(x), next(nullptr) {};

    ListNode(int x, ListNode *next) : val(x), next(next) {};
};

ListNode *createList(std::vector<int>);

void printList(ListNode *);

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *createTree(std::vector<std::vector<int>>);

#endif //UNTITLED_STRUC_H
