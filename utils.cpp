//
// Created by chesh on 2023/3/14.
//
#include <iostream>
#include "utils.h"
#include <map>
#include <unordered_map>
#include <string>


void printMap(std::map<std::string, int> x) {
    return printMapString(x);
}

void printMap(std::unordered_map<std::string, int> x) {
    return printMapString(x);
}


void printMap(std::map<int, int> x) {
    std::map<std::string, int> tmp;
    for (auto i = x.begin(); i != x.end(); i++) {
        tmp[std::to_string(i->first)] = i->second;
    }

    return printMapString(tmp);
}

void printMap(std::unordered_map<int, int> x) {
    std::map<std::string, int> tmp;
    for (auto i = x.begin(); i != x.end(); i++) {
        tmp[std::to_string(i->first)] = i->second;
    }

    return printMapString(tmp);
}

