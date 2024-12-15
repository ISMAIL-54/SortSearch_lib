#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <forward_list>
#include <list>
#include "sort.hpp"

bool comp(char a, char b) {
    bool result = (a > b) ? false : true;
    return result;
}

int main() {
    std::forward_list<char> str = {'a', 's', 'd', 'f', 'j', 'd', 'f', 'l', 's'};
    std::forward_list<char>::iterator iter;
    for (iter = str.begin(); iter != str.end(); iter++) {
        std::cout << *iter;
    }
    std::cout << std::endl;
    sl::quick_sort(str.begin(), str.end());
    for (iter = str.begin(); iter != str.end(); iter++) {
        std::cout << *iter;
    }
    std::cout << std::endl;
    return 0;
}
