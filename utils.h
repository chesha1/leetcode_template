//
// Created by chesh on 2023/3/14.
//

#ifndef UNTITLED_UTILS_H
#define UNTITLED_UTILS_H

#include <iomanip>
#include <map>
#include <string>

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
void printNor(T x) {
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


#endif //UNTITLED_UTILS_H

