#include <iostream>
#include <iomanip>
#include <typeinfo>
#include <boost/type_index.hpp>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>
#include <string>
#include <map>
#include <cmath>

using namespace std;

// print contents of STL container
// print vector, set
template<typename T>
void printStl(T x) {
    for (auto i = x.begin(); i != x.end(); i++) {
        std::cout << *i << "    ";
    }
    std::cout << std::endl;
}

// print map
// template<typename T>
// void printMap(T x) {
//     int length = 0;
//     for (auto i = x.begin(); i != x.end(); i++) {
//         if((i->first).size() > length) length = (i->first).size();
//     }
//     for (auto i = x.begin(); i != x.end(); i++) {
//         std::cout << setw(length) << i->first << " : " << i->second << endl;
//     }

// }

void printMap(map<int,int> x){
    cout << "abc"<<endl;
}

template<typename T>
void printMap(T x){
    cout << "others"<<endl;
}

// print basic variable
template<typename T>
void printNor(T x) {
    std::cout << x << std::endl;
}

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


// print type of variable
template<typename T>
void printType(T x)
{
    cout<<boost::typeindex::type_id_with_cvr<decltype(x)>().pretty_name()<<endl;
}

vector<string> commonChars(vector<string>& words) {

    map<string,int> min_counts;
    for(int i =97;i<=122;i++){
        string tmp(1,char(i));
        min_counts[tmp]=10000;
    }


    map<string,int> counts;
    for (auto i = words.begin();i!=words.end();i++){
        for(auto j:*i){
            string tmp(1,j);
            counts[tmp]=counts[tmp]+1;
        }

        for(auto j = min_counts.begin();j!=min_counts.end();j++)
        {
            
            if(counts[j->first]<j->second) j->second=counts[j->first];
            
        }
        
        counts={};
    }

    vector<string> res={};

    for (auto i = min_counts.begin();i!=min_counts.end();i++)
    {
        while(true)
        {
            if(i->second==0) break;
            res.push_back(i->first);
            i->second=i->second-1;
        }
        



    }
    return res;
    }

// set.count
// vector create (10,2)
// sort(key.begin(), key.end());
// paixu string changyong fangfa



int main() {
    
    map<int,int> a;
    a[1]=1;
    printMap(a);
    



}
