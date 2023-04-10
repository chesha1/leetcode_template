#include <iostream>
#include <iterator>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <string>
#include "utils.h"

using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

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

TreeNode *createTree(vector<vector<int> > data) {
    vector<TreeNode *> mem_addr = {};
    for (auto i = data.begin(); i != data.end(); i++) {
        auto temp = *i;
        for (auto j = temp.begin(); j!=temp.end();j++){
            mem_addr.push_back(new TreeNode(*j));
        }
    }

    int length = mem_addr.size();
    for(auto i=0; i < length ; i++){
        if (2*i<length-1){
            mem_addr[i]->left=mem_addr[2*i+1];
            mem_addr[i]->right=mem_addr[2*i+2];
            if (mem_addr[2*i+1]->val==-1) mem_addr[i]->left=nullptr;
            if (mem_addr[2*i+2]->val==-1) mem_addr[i]->right=nullptr;
        }
        else{
            mem_addr[i]->left=nullptr;
            mem_addr[i]->right=nullptr;
        }
        
    }
    return mem_addr[0];
}

void printList(ListNode *head) {
    ListNode *p = head;
    while (p != nullptr) {
        cout << p->val << "    ";
        p = p->next;
    }
    cout << endl;
}






int main() {
    vector<vector<int> > a={{1},{-1,2},{-1,-1,3,-1}};


}

