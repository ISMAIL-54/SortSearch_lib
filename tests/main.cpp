#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <forward_list>
#include <list>
#include "algorithms.hpp"

bool comp(int a, int b) {
    return a > b;
}

int main() {
    std::vector<int> numbers = {1, 234, 10, -10, 300};
    std::vector<int>::iterator iter;
    for (iter = numbers.begin(); iter != numbers.end(); iter++) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl; 
    sl::merge_sort(numbers.begin(), numbers.end());
    for (iter = numbers.begin(); iter != numbers.end(); iter++) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl; 
    int result = sl::binary_search(numbers.begin(), numbers.end(), 1);
    if (result != -1)
        std::cout << "Index of 1 is " << result << std::endl;
    else
        std::cout << "Not found" << std::endl;
    return 0;
}
