#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <forward_list>
#include <list>
#include "algorithms.hpp"

bool comp(char a, char b) {
    bool result = (a > b) ? false : true;
    return result;
}

int main() {
/*    std::vector<char> str = {'a', 's', 'd', 'f', 'j', 'd', 'f', 'l', 's'};
    std::vector<char>::iterator iter;
    for (iter = str.begin(); iter != str.end(); iter++) {
        std::cout << *iter;
    }
    std::cout << std::endl;
    sl::quick_sort(str.begin(), str.end());
    for (iter = str.begin(); iter != str.end(); iter++) {
        std::cout << *iter;
    }
    std::cout << std::endl; */
    std::vector<int> numbers = {14, 43, 421, 1, 432};
    std::vector<int>::iterator iter;
    for (iter = numbers.begin(); iter != numbers.end(); iter++) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl; 
    sl::quick_sort(numbers.begin(), numbers.end());
    for (iter = numbers.begin(); iter != numbers.end(); iter++) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl; 
    return 0;
}
