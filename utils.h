//
// Created by chesh on 2023/3/14.
//

#ifndef UNTITLED_UTILS_H
#define UNTITLED_UTILS_H

#include <iomanip>
#include <map>
#include <string>
#include <unordered_map>

// print contents of STL container
// print vector, set
template<typename T>
void printStl(T x, bool end = true) {
    if (x.size() == 0) return;
    for (auto i = x.begin(); i != x.end(); i++) {
        auto tmp = i;
        tmp++;
        if (tmp == x.end()) std::cout << *i;
        else std::cout << *i << "    ";
    }
    if (end == true) std::cout << std::endl;

}
//print contents of 2D STL container
//vector<vector<int>>
template<typename T>
void printStl2D(T x) {
    if (x.size() == 0) return;
    std::cout << "[";
    for (auto i = x.begin(); i != x.end(); i++) {
        std::cout << "[";
        printStl(*i, false);
        auto tmp = i;
        tmp++;
        if (tmp == x.end()) std::cout << "]";
        else std::cout << "]," << std::endl;
    }
    std::cout << "]" << std::endl;
}

// print map
template<typename T>
void printMapString(T x) {
    int length = 0;
    for (auto i = x.begin(); i != x.end(); i++) {
        if ((i->first).size() > length) length = (i->first).size();
    }
    for (auto i = x.begin(); i != x.end(); i++) {
        std::cout << std::setw(length) << i->first << " : " << i->second << std::endl;
    }
}


// print basic variable
template<typename T>
void printBasic(T x) {
    std::cout << x << std::endl;
}

template<typename T>
constexpr auto type_name() {
    std::string_view name, prefix, suffix;
#ifdef __clang__
    name = __PRETTY_FUNCTION__;
  prefix = "auto type_name() [T = ";
  suffix = "]";
#elif defined(__GNUC__)
    name = __PRETTY_FUNCTION__;
    prefix = "constexpr auto type_name() [with T = ";
    suffix = "]";
#elif defined(_MSC_VER)
    name = __FUNCSIG__;
  prefix = "auto __cdecl type_name<";
  suffix = ">(void)";
#endif
    name.remove_prefix(prefix.size());
    name.remove_suffix(suffix.size());
    return name;
}

// print type of variable
template<typename T>
void printType(T x) {
    std::cout << type_name<decltype(x)>() << std::endl;
}


void printMap(std::map<std::string, int>);

void printMap(std::map<int, int>);

void printMap(std::unordered_map<int, int>);

void printMap(std::unordered_map<std::string, int>);


#endif //UNTITLED_UTILS_H

