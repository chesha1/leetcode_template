#include <iostream>
#include <iterator>
#include <vector>
#include <stack>
#include <set>
#include <deque>
#include <unordered_set>
#include <algorithm>
#include <string>
#include "utils.h"
#include "struc.h"

using namespace std;

vector<string> letterCombinations(string digits) {

    int len = digits.size();
    vector<string> ans;
    unordered_map<char, string> table;
    table['2'] = "abc";
    table['3'] = "def";
    table['4'] = "ghi";
    table['5'] = "jkl";
    table['6'] = "mno";
    table['7'] = "pqrs";
    table['8'] = "tuv";
    table['9'] = "wxyz";

    reverse(digits.begin(), digits.end());
    if (len == 0) return ans;
    for (auto i: table[digits.back()]) {
        string temp1(1, i);
        ans.push_back(temp1);
    }
    digits.pop_back();
    len = len - 1;
    int length;

    while (len > 0) {
        length = ans[0].size();
        for (auto i = 0; ; ) {
            if(ans[i].size()!=length) break;
            string s1 = ans[i];
            length = s1.size();
            ans.erase(ans.begin());
            for (auto j: table[digits.back()]) {
                string temp1(1, j);
                string temp2 = s1 + temp1;
                ans.push_back(temp2);
            }


        }
        digits.pop_back();
        len = len - 1;
    }

    return ans;

}

int main() {
    string s = "222";
    printStl(letterCombinations(s));


}

